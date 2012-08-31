#ifndef FB2MAIN_H
#define FB2MAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QDockWidget;
class QFile;
class QMenu;
class QModelIndex;
class QTextEdit;
class QTreeView;
class QWebInspector;
QT_END_NAMESPACE

class FbCodeEdit;
class FbTreeView;
class FbHeadView;
class FbTextFrame;
class FbTextEdit;

class FbMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ViewMode { FB2, XML };
    explicit FbMainWindow(const QString &filename = QString(), ViewMode mode = FB2);

protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void logMessage(const QString &message);

private slots:
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();

    void about();
    void documentWasModified();
    void checkScintillaUndo();
    void treeDestroyed();
    void logDestroyed();
    void logShowed();
    void viewCode();
    void viewText();
    void viewHead();
    void viewTree();

    void cleanChanged(bool clean);
    void canUndoChanged(bool canUndo);
    void canRedoChanged(bool canRedo);
    void status(const QString &text);
    void clipboardDataChanged();
    void selectionChanged();
    void undoChanged();
    void redoChanged();
    void openSettings();

private:
    bool loadXML(const QString &filename);
    QString appTitle() const;

private:
    void createHead();
    void createTree();
    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    void setModified(bool modified);
    bool maybeSave();
    bool saveFile(const QString &fileName, const QString &codec = QString());
    void setCurrentFile(const QString &fileName = QString());
    FbMainWindow *findFbMainWindow(const QString &fileName);

    FbTextFrame *textFrame;
    FbCodeEdit *codeEdit;
    FbHeadView *headTree;
    QTextEdit *noteEdit;
    QToolBar *toolEdit;
    QDockWidget *dockTree;
    QWebInspector *inspector;
    QTextEdit *messageEdit;
    QString curFile;
    bool isSwitched;
    bool isUntitled;

    QMenu
        *menuEdit,
        *menuText,
        *menuView;

    QAction
        *actionBack,
        *actionForward,
        *actionUndo,
        *actionRedo,
        *actionCut,
        *actionCopy,
        *actionPaste,
        *actionSelect,
        *actionFind,
        *actionReplace,
        *actionImage,
        *actionNote,
        *actionLink,
        *actionBody,
        *actionTitle,
        *actionEpigraph,
        *actionSubtitle,
        *actionAnnot,
        *actionPoem,
        *actionDate,
        *actionStanza,
        *actionAuthor,
        *actionSection,
        *actionTextBold,
        *actionTextItalic,
        *actionTextStrike,
        *actionTextCode,
        *actionTextSub,
        *actionTextSup,
        *actionInspect,
        *actionZoomIn,
        *actionZoomOut,
        *actionZoomReset
    ;
};

#endif // FB2MAIN_H
