#include <messenger/ui/menu/helpmenu.hpp>
#include <QDesktopServices>
#include <QUrl>

void messenger::helpmenu::homepage_trigger() {
  QDesktopServices::openUrl(QUrl("https://github.com/Siam11651/messenger-qt"));
}

void messenger::helpmenu::about_trigger() {
  
}

messenger::helpmenu::helpmenu() : QMenu() {
  setTitle("Help");

  m_homepage_action = new QAction("Homepage");
  m_about_action = new QAction("About");

  addAction(m_homepage_action);
  addAction(m_about_action);
  connect(m_homepage_action, &QAction::triggered, this, &messenger::helpmenu::homepage_trigger);
  connect(m_about_action, &QAction::triggered, this, &messenger::helpmenu::about_trigger);
}

messenger::helpmenu::~helpmenu() {

}