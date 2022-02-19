#include "includes/aboutme.h"
#include "ui_aboutme.h"

AboutMe::AboutMe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMe)
{
    ui->setupUi(this);
    QPalette p = ui -> textBrowser -> palette();
    // p.setColor(QPalette::Base, "#1e1e1e");
    p.setColor(QPalette::Base, "#4a0d85");
    p.setColor(QPalette::Text, Qt::yellow);
    ui -> textBrowser -> setPalette(p);

}

AboutMe::~AboutMe()
{
    delete ui;
}

void AboutMe::on_viewLinkedInBtn_clicked()
{
    QString url = "https://www.linkedin.com/in/sroyuniquealgo11290157/";
    QDesktopServices::openUrl(url);
}

void AboutMe::on_viewProjectsBtn_clicked()
{
    QString url = "https://github.com/Subhadip11290157";
    QDesktopServices::openUrl(url);
}

void AboutMe::on_viewBlogBtn_clicked()
{
    QString url = "https://bits-n-bytes-cse.blogspot.com/";
    QDesktopServices::openUrl(url);
}

