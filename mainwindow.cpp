#include "mainwindow.h"
#include "ui_mainwindow.h"

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

double firstNum, secondNum, result;

void MainWindow::on_btnAdd_clicked()
{
    firstNum = ui->txtFirstNum->text().toDouble(); // convert first number to double
    secondNum = ui->txtSecondNum->text().toDouble(); // convert second number to double
    result = firstNum + secondNum;

    //The use of static_cast<int>(result) is intended to check if the result is an integer.
    //The idea is to determine if the result has any fractional part. If result is equal to
    //static_cast<int>(result), it means that the result has no fractional part and can be displayed
    //without decimal places. This way, operations like 20 - 5 will display 15 instead of 15.0000

    if (result == static_cast<int>(result)) {

        // 'f': fixed-point notation
        // Always uses fixed-point notation; No decimal places here

        ui->txtResult->setText(QString::number(result, 'f', 0));

    } else {
        // 'g': general format
        // displays to 7 digits
        ui->txtResult->setText(QString::number(result, 'g', 7));
    }
}


void MainWindow::on_btnSubstract_clicked()
{
    firstNum = ui->txtFirstNum->text().toDouble();
    secondNum = ui->txtSecondNum->text().toDouble();
    result = firstNum - secondNum;

    if (result == static_cast<int>(result)) {
        ui->txtResult->setText(QString::number(result, 'f', 0));

    } else {
        ui->txtResult->setText(QString::number(result, 'g', 7));

}
}

void MainWindow::on_btnDivide_clicked()
{
    firstNum = ui->txtFirstNum->text().toDouble();
    secondNum = ui->txtSecondNum->text().toDouble();
    result = firstNum / secondNum;

    if (result == static_cast<int>(result)) {
        ui->txtResult->setText(QString::number(result, 'f', 0));

    } else {
        ui->txtResult->setText(QString::number(result, 'g', 7));

    }
}


void MainWindow::on_btnMultiply_clicked()
{
    firstNum = ui->txtFirstNum->text().toDouble();
    secondNum = ui->txtSecondNum->text().toDouble();
    result = firstNum * secondNum;

    if (result == static_cast<int>(result)) {
        ui->txtResult->setText(QString::number(result, 'f', 0));

    } else {
        ui->txtResult->setText(QString::number(result, 'g', 7));

    }
}

