#include <QDesktopServices>
#include <messenger/ui/popup_page.hpp>

void messenger::popup_page::handle_urlchange(const QUrl &url) {
  if (!m_loaded) {
    QDesktopServices::openUrl(url);

    m_loaded = true;

    deleteLater();
  }
}

messenger::popup_page::popup_page(QWebEngineProfile *const _profile)
    : QWebEnginePage(_profile), m_loaded(false) {
  connect(this, &messenger::popup_page::urlChanged, this,
          &messenger::popup_page::handle_urlchange);
}

messenger::popup_page::~popup_page() {}