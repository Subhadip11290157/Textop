#include "includes/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMainWindow::setWindowIcon(QIcon(":/pics/logo.png"));
    subScript = new QAction("Sub", this);
    subScript -> setIcon(QIcon::fromTheme(":/pics/sub.png"));
    subScript->setCheckable(true);
    subScript->setChecked(false);
    connect(subScript, SIGNAL(triggered()), this, SLOT(subscript_Checked()));

    superScript = new QAction("Super", this);
    superScript -> setIcon(QIcon::fromTheme(":/pics/super.png"));
    superScript->setCheckable(true);
    superScript->setChecked(false);
    connect(superScript, SIGNAL(triggered()), this, SLOT(superscript_Checked()));

    ui -> toolBar -> addAction(subScript);
    ui -> toolBar -> addAction(superScript);

}


// destructor
MainWindow::~MainWindow()
{
    delete ui;
}


// Options under "File"
//    -> new
//    -> open
//    -> save
//    -> save as
//    -> exit

// option - new
void MainWindow::on_actionNew_triggered()
{
    currentFileName = "";
    ui->textEdit ->setPlainText("");
}

// option - open
void MainWindow::on_actionOpen_triggered()
{
    QString openFile = QFileDialog::getOpenFileName(this, "Open A File");
    currentFileName = openFile;

    QFile file(openFile);
    QString line;

    if(file.open(QIODevice :: ReadOnly | QIODevice :: Text))
    {
        QTextStream textStream(&file);

        while (!textStream.atEnd())
        {
            line.append(textStream.readLine()+"\n");
        }
    }

    ui -> textEdit -> setPlainText(line);

}

// option - save
void MainWindow::on_actionSave_triggered()
{
    if(currentFileName == ""){
        on_actionSave_As_triggered();
    }
    else{
        QFile saveFile(currentFileName);
        if(saveFile.open(QFile :: WriteOnly | QFile :: Text)){
            QTextStream  out(&saveFile);
            out << ui -> textEdit -> toPlainText();
            saveFile.flush();
            saveFile.close();
        }
    }

    ui -> statusBar -> showMessage("Saved to " + currentFileName);
}

// option - save as
void MainWindow::on_actionSave_As_triggered()
{
    QString saveFileName = QFileDialog::getSaveFileName(this, "Save As");
    if(!saveFileName.isEmpty())
    {
        currentFileName = saveFileName;
        on_actionSave_triggered();
    }
}

// option - exit
void MainWindow::on_action_Exit_triggered()
{
   QApplication::quit();
}


// Options under "Edit"
//    -> cut
//    -> copy
//    -> paste
//    -> undo
//    -> redo

// option - cut
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

// option - copy
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

// option - paste
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

// option - undo
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

// option - redo
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


// Options for Styling/Formatting:-
//    -> bold
//    -> subscript
//    -> superscript

// option - Bold
void MainWindow::on_actionBold_triggered()
{
    QFont font = ui -> textEdit -> currentFont();
    font.bold() == true ? font.setBold(false) : font.setBold(true);
    ui -> textEdit -> setCurrentFont(font);
}

// option - Subscript
void MainWindow::subscript_Checked()
{
    superScript -> setChecked(false);
    QTextCharFormat format;

    if(subScript -> isChecked())
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);

    ui -> textEdit -> mergeCurrentCharFormat(format);

}

// option - Superscript
void MainWindow::superscript_Checked()
{
    subScript -> setChecked(false);
    QTextCharFormat format;

    if(superScript -> isChecked())
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);

    ui -> textEdit -> mergeCurrentCharFormat(format);

}

// The About Me Section
void MainWindow::on_actionAbout_Me_triggered()
{
    AboutMe aboutMe;
    aboutMe.setWindowTitle("My Resume");
    aboutMe.setModal(true);
    aboutMe.exec();
}

void MainWindow::on_pushButton_clicked()
{
    on_actionAbout_Me_triggered();
}

