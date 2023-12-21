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

void MainWindow::ShowList() {
    foreach (auto item, _phoneBook) {
        auto result = ui->listPhones->findItems(item->getPhone(), Qt::MatchExactly);
        if (result.isEmpty()) {
            ui->listPhones->addItem(item->getPhone());
        }
    }
}

void MainWindow::on_buttonSave_clicked()
{
    _selectedItem = new PhoneBookItem(ui->inputName->text(), ui->inputPhone->text());

    auto flag = false;
    foreach (auto item, _phoneBook) {
        if (item->getPhone() == _selectedItem->getPhone()) {
            item->setName(_selectedItem->getName());
            flag = true;
        }
    }

    if (!flag) {
        _phoneBook.append(_selectedItem);
        ShowList();
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

void MainWindow::on_buttonDelete_clicked()
{
    _selectedItem = new PhoneBookItem(ui->inputName->text(), ui->inputPhone->text());

    int i = 0;
    foreach (auto item, _phoneBook) {
        if (item->getPhone() == _selectedItem->getPhone()) {
            _phoneBook.removeAt(i);
        }
        i += 1;
    }

    ui->listPhones->takeItem(ui->listPhones->currentIndex().row());
}

