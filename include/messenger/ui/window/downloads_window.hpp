#ifndef DOWNLOADS_WINDOW_H
#define DOWNLOADS_WINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QScrollArea>

namespace messenger {
class main_window;

class downloads_window : public QDialog {
private:
  QVBoxLayout *m_root_layout;
  QScrollArea *m_scroll_area;
  QWidget *m_central_widget;
  QVBoxLayout *m_items_layout;

public:
  downloads_window();
  void closeEvent(QCloseEvent *e) override;
  ~downloads_window();
};
} // namespace messenger

#endif