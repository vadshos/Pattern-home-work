#include <iostream>
#include"FacadeFileBase.h"

int main()
{
    CollectionWord fileBase;
    fileBase.addWord(new Word("Bus", "Authobus"));
    //fileBase.translate("Bus",FacadeFileBase::TranslateType::EnToRU);
}


