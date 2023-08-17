#include "mainwindow.h"

#include <QApplication>
#include <dqlite.h>
#include <sqlcipher/sqlite3.h>
#include <sqlcipher/sqlite3ext.h>
#include <QtCore/QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

int main(int argc, char *argv[])
{
    // Create a QApplication object
    QApplication app(argc, argv);

    // Create a connection to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");
    db.setDatabaseName("cluster.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError().text();
        return 1;
    }

    // Create a Dqlite server
    int server_fd;
    dqlite_server *server;

    // Create the server using the `dqlite_server_create` function
    server_fd = dqlite_server_create("localhost", &server);
    if (server_fd < 0) {
        qDebug() << "Error creating server: " << strerror(errno);
        return 1;
    }
//    // Set the connect function.
//    const char *host = "localhost";
//    dqlite_server_set_auto_join(server, &host, NULL);

    // Start the server
    dqlite_server_start(server);

    // Create a Dqlite node
    int node_fd;
    dqlite_node *node;

    node_fd = dqlite_node_create(server_fd, "node1", "node1.db", &node);
    if (node_fd < 0) {
        qDebug() << "Error creating node: " << strerror(errno);
        return 1;
    }

    // Start the node
    dqlite_node_start(node);

    // Create a QSqlQuery object
    QSqlQuery query;

    // Create the table
    query.prepare("CREATE TABLE node1 (id INTEGER PRIMARY KEY, name TEXT);");
    if (!query.exec()) {
        qDebug() << "Error creating table: " << query.lastError().text();
        return 1;
    }

    // Insert a row into the table
    query.prepare("INSERT INTO node1 (name) VALUES ('Node 1');");
    if (!query.exec()) {
        qDebug() << "Error inserting row: " << query.lastError().text();
        return 1;
    }

    // Get the number of rows in the table
    query.clear();
    query.prepare("SELECT COUNT(*) FROM node1");
    query.exec();
    if (query.lastError().isValid()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return 1;
    }

    // Get the number of rows
    int num_rows = query.value(0).toInt();
    qDebug() << "There are " << num_rows << " rows in the table.";

    // Close the connection to the database
    dqlite_server_stop(server);
    dqlite_node_stop(node);

    // Run the application
    return app.exec();
}
