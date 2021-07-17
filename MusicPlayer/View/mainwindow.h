#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaContent>
#include "myqss.h"
#include <QDir>
#include "Commands/command.h"
#include <QFileDialog>
#include <QStandardPaths>
class Notification;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init_player();

    void set_addMusic_command(std::shared_ptr<Command> cmd);
    std::shared_ptr<Notification> get_update_notification();
    void update(QStringList );
    QString formatTime(int ms);

private slots:
    //automatic generated
    void on_skipforward_clicked();

    void on_Pause_clicked();

    void on_skipbackward_clicked();

    void on_playlist_clicked();

    void on_addMusic_clicked();

    void on_positionSlider_sliderReleased();

    void on_volume_clicked();

    void on_volumeSlider_sliderReleased();

    void on_musictable_cellDoubleClicked(int row, int column);

    void on_playmode_clicked();
    //manually added
    void updateInfo();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;

    std::shared_ptr<Command> addmusiccommand;
    std::shared_ptr<Notification> update_view_notification;

};



#endif // MAINWINDOW_H
