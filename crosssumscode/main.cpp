#include "includes.h"

int main(int argc, char *argv[])
//nothing to see here. Create our gui, show it, then once it's closed, we're done
{
    QApplication a(argc, argv);
    CrossSumsUI w;
    w.show();

    return a.exec();
}
