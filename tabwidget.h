#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QWebEnginePage>

QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

class WebView;

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget *parent = nullptr);
    ~TabWidget();

    WebView *currentWebView() const;

signals:
    // current tab/page signals
    void loadProgress(int progress);
    void titleChanged(const QString &title);
    void urlChanged(const QUrl &url);
    void iconChanged(const QIcon &icon);

public slots:
    // current tab/page slots
    void setUrl(const QUrl &url);
    void triggerWebPageAction(QWebEnginePage::WebAction action);

    WebView *createTab(bool makeCurrent = true);
    void closeTab(int index);

private slots:
    void handleCurrentChanged(int index);

private:
    WebView *webView(int index) const;
    void setupView(WebView *webView);
};

#endif // TABWIDGET_H
