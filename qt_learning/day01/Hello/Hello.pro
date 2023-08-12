
QT += widgets

TEMPLATE = app    #程序类型
TARGET = Hello    #生产的目标文件
INCLUDEPATH += .  #需要包含的目录

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS  #过时功能会有警告

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
SOURCES += main.cpp  #源文件
HEADERS +=  # 头文件
LIBS += #库文件
FORMS += #其他文件，例如ui文件
