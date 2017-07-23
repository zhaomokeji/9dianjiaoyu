#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    QStringList getResourceDirs();

private:
    Ui::MainWindow *ui;

private slots:
    void dirItemClicked(QModelIndex index);
    void fileItemClicked(QModelIndex index);
};

#endif // MAINWINDOW_H
