#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebEngineView>

class WebPage;

class WebView : public QWebEngineView {
  Q_OBJECT

public:
  WebView(QWidget *parent = nullptr);

protected:
  QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;
};

#endif
