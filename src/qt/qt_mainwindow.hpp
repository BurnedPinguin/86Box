#ifndef QT_MAINWINDOW_HPP
#define QT_MAINWINDOW_HPP

#include <QMainWindow>
#include <QLabel>
#include <qevent.h>

namespace Ui {
class MainWindow;
}

class GLESWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showMessage(const QString& header, const QString& message);
signals:
    void paint(const QImage& image);
    void blitToWidget(int x, int y, int w, int h);
    void resizeContents(int w, int h);
    void pollMouse();
    void updateStatusBarPanes();
    void updateStatusBarActivity(int tag, bool active);
    void updateStatusBarEmpty(int tag, bool empty);

    void setFullscreen(bool state);
    void setMouseCapture(bool state);

    void showMessageForNonQtThread(const QString& header, const QString& message);
private slots:
    void on_actionFullscreen_triggered();
    void on_actionSettings_triggered();
    void on_actionExit_triggered();
    void on_actionPause_triggered();
    void on_actionCtrl_Alt_Del_triggered();
    void on_actionCtrl_Alt_Esc_triggered();
    void on_actionHard_Reset_triggered();
    void on_actionRight_CTRL_is_left_ALT_triggered();
    void on_actionKeyboard_requires_capture_triggered();

    void showMessage_(const QString& header, const QString& message);
protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
private:
    struct DeltaPos {
        int x = 0;
        int y = 0;
        int z = 0;
    };
    Ui::MainWindow *ui;
    DeltaPos mouseDelta;
    QWindow* sdl_wrapped_window;
    QWidget* sdl_wrapped_widget;
    GLESWidget* hw_widget;
    QTimer* sdl_timer;
};

#endif // QT_MAINWINDOW_HPP
