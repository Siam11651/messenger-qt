#ifndef POPUP_PAGE_H
#define POPUP_PAGE_H

#include <QWebEnginePage>
#include <QWebEngineProfile>

namespace messenger {
class popup_page : public QWebEnginePage {
private:
  bool m_loaded;

public slots:
  void handle_urlchange(const QUrl &url);

public:
  popup_page(QWebEngineProfile *const _profile);
  ~popup_page();
};
} // namespace messenger

#endif