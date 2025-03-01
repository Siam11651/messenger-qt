#include <messenger/ui/widget/download_item.hpp>

messenger::download_item::download_item() : QWidget() {
  setContentsMargins(8, 4, 8, 4);

  m_root_layout = new QVBoxLayout();

  m_root_layout->setAlignment(Qt::AlignTop);
  setLayout(m_root_layout);

  m_filename_label = new QLabel("Kekw");

  m_root_layout->addWidget(m_filename_label);

  m_buttons_layout = new QHBoxLayout();

  m_buttons_layout->setAlignment(Qt::AlignRight);
  m_root_layout->addLayout(m_buttons_layout);

  m_pause_button = new QPushButton("Pause");
  m_cancel_button = new QPushButton("Cancel");

  m_buttons_layout->addWidget(m_pause_button);
  m_buttons_layout->addWidget(m_cancel_button);
}

messenger::download_item::~download_item() {
  m_pause_button->deleteLater();
  m_cancel_button->deleteLater();
  m_buttons_layout->deleteLater();
  m_filename_label->deleteLater();
  m_root_layout->deleteLater();
}