#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//#include <dqlite.h>
//#include <QtCore/QCoreApplication>
//#include <QtCore/QDebug>

//int main(int argc, char* argv[])
//{
//    QCoreApplication a(argc, argv);

//    // Create a dqlite node.
//    dqlite_node *node;
//    int rv = dqlite_node_create(1, "127.0.0.1:9001", "/tmp/dqlite", &node);
//    if (rv != SQLITE_OK) {
//        fprintf(stderr, "create node: %s\n", dqlite_node_errmsg(node));
//        dqlite_node_destroy(node);
//        return 1;
//    }

//    // Create a dqlite connection to the node.
//    int conn = dqlite_node_start(node);
//    if (conn != SQLITE_OK) {
//        fprintf(stderr, "start node: %s\n", dqlite_node_errmsg(node));
//        dqlite_node_destroy(node);
//        return 1;
//    }

//    // Create a distributed database on the node.
//    char *err_msg = NULL;
//    int db = dqlite_d(conn, "mydb", &err_msg);
//    if (db != SQLITE_OK) {
//        fprintf(stderr, "create database: %s\n", err_msg);
//        free(err_msg);
//        dqlite_conn_close(conn);
//        dqlite_node_destroy(node);
//        return 1;
//    }

//    // Do something with the database.
//    // ...

//    // Close the connection.
//    dqlite_conn_close(conn);

//    // Destroy the node.
//    dqlite_node_destroy(node);

//    return a.exec();
//}

