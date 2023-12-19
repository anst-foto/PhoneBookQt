#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _selectedItem = nullptr;

    _phoneBook.append(new PhoneBookItem("Andrey", "+79042144491"));
    _phoneBook.append(new PhoneBookItem("Andrey", "+74732575755"));

    foreach (auto item, _phoneBook) {
        ui->listPhones->addItem(item->getPhone());
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    delete _selectedItem;
}

void MainWindow::on_buttonSave_clicked()
{
    _selectedItem = new PhoneBookItem(ui->inputName->text(), ui->inputPhone->text());

    foreach (auto item, _phoneBook) {
        if (item->getPhone() == _selectedItem->getPhone()) {
            item->setName(_selectedItem->getName());
        } else {
            _phoneBook.append(_selectedItem);
        }
    }
}


void MainWindow::on_buttonClear_clicked()
{
    ui->inputName->clear();
    ui->inputPhone->clear();
}


void MainWindow::on_listPhones_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    foreach (auto item, _phoneBook) {
        if (item->getPhone() == current->text()) {
            ui->inputPhone->setText(item->getPhone());
            ui->inputName->setText(item->getName());
        }
    }
}

