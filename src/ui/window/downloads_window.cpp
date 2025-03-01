#include <iostream>
#include <messenger/ui/main_window.hpp>
#include <messenger/ui/window/downloads_window.hpp>
#include <messenger/ui/widget/download_item.hpp>

messenger::downloads_window::downloads_window() : QDialog() {
  setWindowTitle("Messenger Qt - Downloads");
  setWindowIcon(QIcon("./assets/messenger.ico"));
  setMinimumWidth(800);
  setMinimumHeight(600);
  
  m_root_layout = new QVBoxLayout();

  m_root_layout->setContentsMargins(0, 0, 0, 0);
  m_root_layout->setAlignment(Qt::AlignTop);
  setLayout(m_root_layout);

  m_scroll_area = new QScrollArea();

  m_scroll_area->setWidgetResizable(true);
  m_root_layout->addWidget(m_scroll_area, 1);

  m_central_widget = new QWidget();

  m_scroll_area->setWidget(m_central_widget);

  m_items_layout = new QVBoxLayout();

  m_items_layout->setAlignment(Qt::AlignTop);
  m_central_widget->setLayout(m_items_layout);

  for(size_t i = 0; i < 1000; ++i) {
    m_items_layout->addWidget(new messenger::download_item());
  }
}

void messenger::downloads_window::closeEvent(QCloseEvent *e) { deleteLater(); }

messenger::downloads_window::~downloads_window() {
  m_items_layout->deleteLater();
  m_central_widget->deleteLater();
  m_scroll_area->deleteLater();
  m_root_layout->deleteLater();
}