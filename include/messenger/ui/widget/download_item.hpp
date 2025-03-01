#ifndef DOWNLOAD_ITEM_H
#define DOWNLOAD_ITEM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace messenger {
class download_item : public QWidget {
private:
  QVBoxLayout *m_root_layout;
  QLabel *m_filename_label;
  QHBoxLayout *m_buttons_layout;
  QPushButton *m_pause_button;
  QPushButton *m_cancel_button;

public:
  download_item();
  ~download_item();
};
} // namespace messenger

#endif