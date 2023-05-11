#include <iostream>

class BRANCH_CLASS;

class FRUIT_CLASS;

class WOOD_CLASS;

class GARDEN_CLASS;

class FRUIT_CLASS {
private:
    unsigned int Weight;
    BRANCH_CLASS *BranchPointer;
public:
    FRUIT_CLASS();

    ~FRUIT_CLASS();

    FRUIT_CLASS(BRANCH_CLASS *);

    FRUIT_CLASS(const FRUIT_CLASS &);

    unsigned int getLength();

    unsigned int getWeight();

    void growthFruit();

    void fadeFruit();

    void pluckFruit();

    void setBranchPointer(BRANCH_CLASS *);

    BRANCH_CLASS *getBranchPointer();

    void increaseWeightsTotal(unsigned int);

    void decreaseWeightsTotal(unsigned int);
};

class BRANCH_CLASS {
private:
    unsigned int FruitsTotal;
    unsigned int WeightsTotal;
    unsigned int Length;
    WOOD_CLASS *WoodPointer;

    struct Fruits {
        unsigned int Length;
        FRUIT_CLASS *FruitPointer;

        Fruits *NextFruit;

        Fruits();

        ~Fruits();
    };

    Fruits *FirstFruit;
    Fruits *LastFruit;
public:
    BRANCH_CLASS();

    BRANCH_CLASS(WOOD_CLASS *);

    ~BRANCH_CLASS();

    BRANCH_CLASS(const BRANCH_CLASS &);

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getHeight();

    unsigned int getLength();

    void growthBranch();

    void fadeBranch();

    void harvestBranch(unsigned int);

    void cutBranch(unsigned int);

    FRUIT_CLASS *getFruitPointer(unsigned int);

    WOOD_CLASS *getWoodPointer();

    void increaseWeightsTotal(unsigned int);

    void decreaseWeightsTotal(unsigned int);

    void increaseFruitsTotal();

    void decreaseFruitsTotal();

    void setWoodPointer(WOOD_CLASS *);

    unsigned int findLength(FRUIT_CLASS *FruitPointer);

};

class WOOD_CLASS {
private:
    unsigned int BranchesTotal;
    unsigned int FruitsTotal;
    unsigned int WeightsTotal;
    unsigned int Height;
    GARDEN_CLASS *GardenPointer;

    struct Branches {
        unsigned int Height;

        BRANCH_CLASS *BranchPointer;

        Branches *NextBranch;

        Branches();

        ~Branches();
    };

    Branches *FirstBranch;
    Branches *LastBranch;
public:
    WOOD_CLASS();

    WOOD_CLASS(GARDEN_CLASS *);

    ~WOOD_CLASS();

    WOOD_CLASS(const WOOD_CLASS &);

    unsigned int getBranchesTotal();

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getNumber();

    unsigned int getHeight();

    void growthWood();

    void fadeWood();

    void harvestWood(unsigned int);

    void cutWood(unsigned int);

    void cloneBranch(BRANCH_CLASS *);

    GARDEN_CLASS *getGardenPointer();

    BRANCH_CLASS *getBranchPointer(unsigned int);

    void increaseWeightsTotal(unsigned int);

    void decreaseWeightsTotal(unsigned int);

    void increaseFruitsTotal(unsigned int Fruits = 1);

    void decreaseFruitsTotal();

    void increaseBranchesTotal();

    void decreaseBranchesTotal();

    unsigned int findHeight(BRANCH_CLASS *BranchPointer);

    void setGardenPointer(GARDEN_CLASS *pClass);

};

class GARDEN_CLASS {
private:
    unsigned int WoodsTotal;
    unsigned int BranchesTotal;
    unsigned int FruitsTotal;
    unsigned int WeightsTotal;
    unsigned int EmptyPlaces;

    struct Woods {
        unsigned int Number;
        WOOD_CLASS *WoodPointer;
        Woods *NextWood;
        Woods *PrevWood;

        Woods();

        ~Woods();
    };

    Woods *FirstWood;
    Woods *LastWood;

public:
    GARDEN_CLASS();

    ~GARDEN_CLASS();

    unsigned int getWoodsTotal();

    unsigned int getBranchesTotal();

    unsigned int getFruitsTotal();

    unsigned int getEmptyPlaces();

    unsigned int getWeightsTotal();

    void plantWood();

    void extractWood(unsigned int);

    void growthGarden();

    void fadeGarden();

    void harvestGarden(unsigned int);

    void cloneWood(unsigned int);

    void increaseWeightsTotal(unsigned int);

    void decreaseWeightsTotal(unsigned int);

    void increaseFruitsTotal(unsigned int = 1);

    void decreaseFruitsTotal();

    void increaseBranchesTotal();

    void decreaseBranchesTotal();

    WOOD_CLASS *getWoodPointer(unsigned int);

    unsigned int findNumber(WOOD_CLASS *WoodPointer);

    void decreaseWoodsTotal();

};

void GARDEN_CLASS::extractWood(unsigned int Number) {
    if (FirstWood == NULL) return;
    if (LastWood->Number < Number) return;
    Woods *Temp = FirstWood;
    Woods *Temp2 = LastWood;
    if (LastWood != FirstWood && LastWood->Number == Number) {
        LastWood = LastWood->PrevWood;
        delete LastWood->NextWood;
        LastWood->NextWood = NULL;
        return;
    }
    while (Temp != NULL && Temp2 != NULL) {
        if (Temp->Number == Number) break;
        if (Temp->Number > Number) return;
        if (Temp2->Number == Number) {
            Temp = Temp2;
            break;
        }
        if (Temp2->Number < Number) return;
        Temp = Temp->NextWood;
        Temp2 = Temp2->PrevWood;
    }
    if (Temp == NULL) return;
    if (LastWood == Temp) {
        if (FirstWood == LastWood) {
            delete FirstWood;
            FirstWood = NULL;
            LastWood = NULL;
            EmptyPlaces = 0;
            WoodsTotal = 0;
        }
    } else {
        if (FirstWood == Temp) {
            FirstWood = FirstWood->NextWood;
            delete FirstWood->PrevWood;
            FirstWood->PrevWood = NULL;
        } else {
            Temp->PrevWood->NextWood = Temp->NextWood;
            Temp->NextWood->PrevWood = Temp->PrevWood;
            delete Temp;
        }
        EmptyPlaces++;
    }
}

void GARDEN_CLASS::plantWood() {
    Woods *NewWood = new Woods;
    NewWood->WoodPointer = new WOOD_CLASS(this);
    if (EmptyPlaces == 0) {
        NewWood->Number = WoodsTotal;
        if (FirstWood == NULL) {
            FirstWood = NewWood;
            LastWood = NewWood;
        } else {
            LastWood->NextWood = NewWood;
            NewWood->PrevWood = LastWood;
            LastWood = LastWood->NextWood;
        }
    } else {
        Woods *Temp = FirstWood;
        unsigned int i = 0;
        while (Temp) {
            if (Temp->Number != i) break;
            Temp = Temp->NextWood;
            i++;
        }
        NewWood->Number = i;
        if (i == 0) {
            FirstWood->PrevWood = NewWood;
            NewWood->NextWood = FirstWood;
            FirstWood = NewWood;
        } else {
            NewWood->PrevWood = Temp->PrevWood;
            NewWood->NextWood = Temp;
            Temp->PrevWood->NextWood = NewWood;
            Temp->PrevWood = NewWood;
        }
        EmptyPlaces--;
    }
    WoodsTotal++;
}

void GARDEN_CLASS::cloneWood(unsigned int Number) {
    if (FirstWood == NULL) return;
    if (LastWood->Number < Number) return;

    WOOD_CLASS *Temp = getWoodPointer(Number);
    if(Temp == NULL) return;

    Woods* NewWood = new Woods;
    NewWood->WoodPointer = new WOOD_CLASS(*Temp);
    NewWood->WoodPointer->setGardenPointer(this);

    FruitsTotal += NewWood->WoodPointer->getFruitsTotal();
    WeightsTotal += NewWood->WoodPointer->getWeightsTotal();
    BranchesTotal += NewWood->WoodPointer->getBranchesTotal();

    if (EmptyPlaces == 0) {
        NewWood->Number = WoodsTotal;
        LastWood->NextWood = NewWood;
        NewWood->PrevWood = LastWood;
        LastWood = LastWood->NextWood;
    } else {
        Woods *Temp = FirstWood;
        unsigned int i = 0;
        while (Temp) {
            if (Temp->Number != i) break;
            Temp = Temp->NextWood;
            i++;
        }
        NewWood->Number = i;
        if (i == 0) {
            FirstWood->PrevWood = NewWood;
            NewWood->NextWood = FirstWood;
            FirstWood = NewWood;
        } else {
            NewWood->PrevWood = Temp->PrevWood;
            NewWood->NextWood = Temp;
            Temp->PrevWood->NextWood = NewWood;
            Temp->PrevWood = NewWood;

        }
        EmptyPlaces--;
    }
    WoodsTotal++;
}

GARDEN_CLASS::Woods::Woods() {
    this->NextWood = NULL;
    this->PrevWood = NULL;
}

GARDEN_CLASS::Woods::~Woods() {
    delete this->WoodPointer;
}

unsigned int GARDEN_CLASS::getWoodsTotal() {
    return WoodsTotal;
}

unsigned int GARDEN_CLASS::getEmptyPlaces() {
    return EmptyPlaces;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    return BranchesTotal;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    return FruitsTotal;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {
    return WeightsTotal;
}

GARDEN_CLASS::GARDEN_CLASS() {
    this->WoodsTotal = 0;
    this->EmptyPlaces = 0;
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->FirstWood = NULL;
    this->LastWood = NULL;
}

GARDEN_CLASS::~GARDEN_CLASS() {
    Woods *Temp = FirstWood;
    while (Temp) {
        Woods *Temp2 = Temp->NextWood;
        delete Temp;
        Temp = Temp2;
    }
    FirstWood = NULL;
    LastWood = NULL;
}

void GARDEN_CLASS::increaseWeightsTotal(unsigned int Weight) {
    this->WeightsTotal += Weight;
}

void GARDEN_CLASS::decreaseWeightsTotal(unsigned int Weight) {
    this->WeightsTotal -= Weight;
}

void GARDEN_CLASS::increaseFruitsTotal(unsigned int Fruit) {
    this->FruitsTotal += Fruit;
}

void GARDEN_CLASS::decreaseFruitsTotal() {
    this->FruitsTotal--;
}

void GARDEN_CLASS::increaseBranchesTotal() {
    this->BranchesTotal++;
}

void GARDEN_CLASS::decreaseBranchesTotal() {
    this->BranchesTotal--;
}

void GARDEN_CLASS::decreaseWoodsTotal() {
    this->WoodsTotal--;
}

unsigned int GARDEN_CLASS::findNumber(WOOD_CLASS *WoodPointer) {
    Woods *Temp = FirstWood;
    while (Temp) {
        if (Temp->WoodPointer == WoodPointer) return Temp->Number;
        Temp = Temp->NextWood;
    }
    return 0;
}

WOOD_CLASS *GARDEN_CLASS::getWoodPointer(unsigned int Number) {
    Woods *Temp = this->FirstWood;
    Woods *Temp2 = this->LastWood;
    while (Temp != NULL && Temp2 != NULL) {
        if (Temp->Number == Number) {
            return Temp->WoodPointer;
        }
        if (Temp2->Number == Number) {
            return Temp2->WoodPointer;
        }
        if (Temp->Number > Number) {
            return NULL;
        }
        if (Temp2->Number < Number) {
            return NULL;
        }
        Temp = Temp->NextWood;
        Temp2 = Temp2->PrevWood;
    }
    return NULL;
}

void GARDEN_CLASS::harvestGarden(unsigned int Weight) {
    Woods *Temp = this->FirstWood;
    while (Temp) {
        Temp->WoodPointer->harvestWood(Weight);
        Temp = Temp->NextWood;
    }
}

void GARDEN_CLASS::fadeGarden() {
    Woods *Temp = this->FirstWood;
    while (Temp) {
        Temp->WoodPointer->fadeWood();
        Temp = Temp->NextWood;
    }
}

void GARDEN_CLASS::growthGarden() {
    Woods *Temp = this->FirstWood;
    while (Temp) {
        Temp->WoodPointer->growthWood();
        Temp = Temp->NextWood;
    }
}

FRUIT_CLASS::FRUIT_CLASS() {
    this->Weight = 0;
    this->BranchPointer = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS *BranchPointer) {
    this->Weight = 0;
    this->BranchPointer = BranchPointer;
}

FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS &object) {
    this->Weight = object.Weight;
}

FRUIT_CLASS::~FRUIT_CLASS() {
    this->pluckFruit();
}

unsigned int FRUIT_CLASS::getLength() {
    return BranchPointer != NULL ? BranchPointer->findLength(this) : 0;
}

unsigned int FRUIT_CLASS::getWeight() {
    return this->Weight;
}

void FRUIT_CLASS::growthFruit() {
    this->increaseWeightsTotal(1);
}

void FRUIT_CLASS::fadeFruit() {
    if (this->Weight != 0) {
        this->decreaseWeightsTotal(1);
    }
}

void FRUIT_CLASS::pluckFruit() {
    this->decreaseWeightsTotal(this->Weight);
}

BRANCH_CLASS *FRUIT_CLASS::getBranchPointer() {
    return this->BranchPointer;
}

void FRUIT_CLASS::increaseWeightsTotal(unsigned int WeightsTotal) {
    this->Weight += WeightsTotal;
    if (this->BranchPointer != NULL)
        this->BranchPointer->increaseWeightsTotal(WeightsTotal);
}

void FRUIT_CLASS::decreaseWeightsTotal(unsigned int WeightsTotal) {
    this->Weight -= WeightsTotal;
    if (this->BranchPointer != NULL)
        this->BranchPointer->decreaseWeightsTotal(WeightsTotal);
}

void FRUIT_CLASS::setBranchPointer(BRANCH_CLASS *BranchPointer) {
    this->BranchPointer = BranchPointer;
}

BRANCH_CLASS::Fruits::Fruits() {
    this->NextFruit = NULL;
}

BRANCH_CLASS::Fruits::~Fruits() {
    delete this->FruitPointer;
}

BRANCH_CLASS::BRANCH_CLASS() {
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->Length = 0;
    this->WoodPointer = NULL;
    this->FirstFruit = NULL;
    this->LastFruit = NULL;
}

BRANCH_CLASS::BRANCH_CLASS(WOOD_CLASS *WoodPointer) {
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->Length = 0;
    this->FirstFruit = NULL;
    this->LastFruit = NULL;
    this->WoodPointer = WoodPointer;
}

BRANCH_CLASS::~BRANCH_CLASS() {
    this->cutBranch(0);
}

unsigned int BRANCH_CLASS::getFruitsTotal() {
    return this->FruitsTotal;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    return this->WeightsTotal;
}

unsigned int BRANCH_CLASS::getHeight() {
    return WoodPointer != NULL ? WoodPointer->findHeight(this) : 0;
}

unsigned int BRANCH_CLASS::getLength() {
    return this->Length;
}

void BRANCH_CLASS::growthBranch() {
    this->Length++;
    Fruits *Temp = this->FirstFruit;
    while (Temp) {
        Temp->FruitPointer->growthFruit();
        Temp = Temp->NextFruit;
    }
    if (this->Length % 2 == 0) {
        Fruits *NewFruit = new Fruits;
        increaseFruitsTotal();
        NewFruit->Length = this->Length;
        NewFruit->FruitPointer = new FRUIT_CLASS(this);
        if (this->FirstFruit == NULL) {
            this->FirstFruit = NewFruit;
            this->LastFruit = FirstFruit;
        } else {
            this->LastFruit->NextFruit = NewFruit;
            this->LastFruit = NewFruit;
        }
    }
}

void BRANCH_CLASS::fadeBranch() {
    this->cutBranch(this->Length - 1);
    Fruits *Temp = this->FirstFruit;
    while (Temp) {
        Temp->FruitPointer->fadeFruit();
        Temp = Temp->NextFruit;
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int Weight) {
    Fruits *Temp = this->FirstFruit;
    while (Temp) {
        if (Temp->FruitPointer->getWeight() >= Weight)
            Temp->FruitPointer->pluckFruit();
        Temp = Temp->NextFruit;
    }
}

void BRANCH_CLASS::cutBranch(unsigned int Length) {
    if (this->Length <= Length) return;
    if (this->Length % 2 == 1 && this->Length - Length == 1) {
        this->Length = Length;
        return;
    }
    this->Length = Length;
    Fruits *Temp = this->FirstFruit;
    if (this->FirstFruit->Length > Length) {
        this->FirstFruit = NULL;
        this->LastFruit = NULL;
    } else {
        Fruits *Prev;
        while (Temp->Length <= Length) {
            Prev = Temp;
            Temp = Temp->NextFruit;
        }
        Prev->NextFruit = NULL;
        this->LastFruit = Prev;
    }
    Fruits *Temp2;
    while (Temp) {
        Temp2 = Temp->NextFruit;
        this->decreaseFruitsTotal();
        delete Temp;
        Temp = Temp2;
    }
}

FRUIT_CLASS *BRANCH_CLASS::getFruitPointer(unsigned int Length) {
    if (Length == 0 || Length % 2 == 1 || Length > this->Length) return NULL;
    Fruits *Temp = this->FirstFruit;
    while (Temp) {
        if (Temp->FruitPointer->getLength() == Length) {
            return Temp->FruitPointer;
        }
        Temp = Temp->NextFruit;
    }
    return NULL;
}

WOOD_CLASS *BRANCH_CLASS::getWoodPointer() {
    return WoodPointer;
}

void BRANCH_CLASS::increaseWeightsTotal(unsigned int Weight) {
    this->WeightsTotal += Weight;
    if (this->WoodPointer != NULL)
        this->WoodPointer->increaseWeightsTotal(Weight);
}

void BRANCH_CLASS::decreaseWeightsTotal(unsigned int Weight) {
    this->WeightsTotal -= Weight;
    if (this->WoodPointer != NULL)
        this->WoodPointer->decreaseWeightsTotal(Weight);
}

void BRANCH_CLASS::increaseFruitsTotal() {
    this->FruitsTotal++;
    if (this->WoodPointer != NULL)
        this->WoodPointer->increaseFruitsTotal();
}

void BRANCH_CLASS::decreaseFruitsTotal() {
    this->FruitsTotal--;
    if (this->WoodPointer != NULL)
        this->WoodPointer->decreaseFruitsTotal();
}

unsigned int BRANCH_CLASS::findLength(FRUIT_CLASS *FruitPointer) {
    Fruits *Temp = FirstFruit;
    while (Temp) {
        if (Temp->FruitPointer == FruitPointer) return Temp->Length;
        Temp = Temp->NextFruit;
    }
    return 0;
}

WOOD_CLASS::Branches::Branches() {
    NextBranch = NULL;
}

WOOD_CLASS::Branches::~Branches() {
    delete this->BranchPointer;
}

WOOD_CLASS::WOOD_CLASS() {
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->Height = 0;
    this->GardenPointer = NULL;
    this->FirstBranch = NULL;
    this->LastBranch = NULL;
}

WOOD_CLASS::WOOD_CLASS(GARDEN_CLASS *GardenPointer) {
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->Height = 0;
    this->FirstBranch = NULL;
    this->LastBranch = NULL;
    this->GardenPointer = GardenPointer;
}

WOOD_CLASS::~WOOD_CLASS() {
    this->cutWood(0);
    if (this->GardenPointer != NULL)
        this->GardenPointer->decreaseWoodsTotal();
}

unsigned int WOOD_CLASS::getBranchesTotal() {
    return this->BranchesTotal;
}

unsigned int WOOD_CLASS::getFruitsTotal() {
    return this->FruitsTotal;
}

unsigned int WOOD_CLASS::getWeightsTotal() {
    return this->WeightsTotal;
}

unsigned int WOOD_CLASS::getNumber() {
    return GardenPointer != NULL ? GardenPointer->findNumber(this) : 0;
}

unsigned int WOOD_CLASS::getHeight() {
    return this->Height;
}

void WOOD_CLASS::growthWood() {
    this->Height++;
    Branches *Temp = this->FirstBranch;
    while (Temp) {
        Temp->BranchPointer->growthBranch();
        Temp = Temp->NextBranch;
    }
    if (this->Height % 3 == 0) {
        Branches *NewBranch = new Branches;
        NewBranch->Height = this->Height;
        NewBranch->BranchPointer = new BRANCH_CLASS(this);
        this->increaseBranchesTotal();
        if (FirstBranch == NULL) {
            FirstBranch = NewBranch;
            LastBranch = FirstBranch;
        } else {
            LastBranch->NextBranch = NewBranch;
            LastBranch = NewBranch;
        }
    }
}

void WOOD_CLASS::setGardenPointer(GARDEN_CLASS *GardenPointer) {
    this->GardenPointer = GardenPointer;
}


void WOOD_CLASS::fadeWood() {
    this->cutWood(this->Height - 1);
    Branches *Temp = this->FirstBranch;
    while (Temp) {
        Temp->BranchPointer->fadeBranch();
        Temp = Temp->NextBranch;
    }
}

void WOOD_CLASS::harvestWood(unsigned int Weight) {
    Branches *Temp = this->FirstBranch;
    while (Temp) {
        Temp->BranchPointer->harvestBranch(Weight);
        Temp = Temp->NextBranch;
    }
}

void WOOD_CLASS::cutWood(unsigned int Height) {
    if (this->Height <= Height) return;
    if (this->Height % 3 == 1 && this->Height - Height == 1) {
        this->Height = Height;
        return;
    }
    if (this->Height % 3 == 2 && this->Height - Height == 1) {
        this->Height = Height;
        return;
    }
    this->Height = Height;
    if (FirstBranch == NULL) return;
    Branches *Temp = this->FirstBranch;
    if (this->FirstBranch->BranchPointer->getHeight() > Height) {
        FirstBranch = NULL;
        LastBranch = NULL;
    } else {
        Branches *Prev;
        while (Temp != NULL && Temp->BranchPointer->getHeight() <= Height) {
            Prev = Temp;
            Temp = Temp->NextBranch;
        }
        Prev->NextBranch = NULL;
        LastBranch = Prev;
    }
    Branches *Temp2;
    while (Temp) {
        Temp2 = Temp->NextBranch;
        this->decreaseBranchesTotal();
        delete Temp;
        Temp = Temp2;
    }
}

GARDEN_CLASS *WOOD_CLASS::getGardenPointer() {
    return this->GardenPointer;
}

BRANCH_CLASS *WOOD_CLASS::getBranchPointer(unsigned int Height) {
    if (Height == 0 || Height % 3 != 0 || Height > this->Height) return NULL;
    Branches *Temp = this->FirstBranch;
    while (Temp) {
        if (Temp->BranchPointer->getHeight() == Height) {
            return Temp->BranchPointer;
        }
        Temp = Temp->NextBranch;
    }
    return NULL;
}

void WOOD_CLASS::cloneBranch(BRANCH_CLASS *BranchPointer) {
    if (BranchPointer == NULL) return;
    if (this->FirstBranch == NULL) return;
    Branches *Temp = this->FirstBranch;
    while (Temp) {
        if (Temp->BranchPointer->getLength() == 0) break;
        Temp = Temp->NextBranch;
    }
    if (Temp == NULL) return;
    delete Temp->BranchPointer;
    Temp->BranchPointer = new BRANCH_CLASS(*BranchPointer);
    Temp->BranchPointer->setWoodPointer(this);
    this->increaseFruitsTotal(Temp->BranchPointer->getFruitsTotal());
    this->increaseWeightsTotal(Temp->BranchPointer->getWeightsTotal());
}

unsigned int WOOD_CLASS::findHeight(BRANCH_CLASS *BranchPointer) {
    Branches *Temp = FirstBranch;
    while (Temp) {
        if (Temp->BranchPointer == BranchPointer) return Temp->Height;
        Temp = Temp->NextBranch;
    }
    return 0;
}

void WOOD_CLASS::increaseWeightsTotal(unsigned int Weight) {
    this->WeightsTotal += Weight;
    if (this->GardenPointer != NULL)
        this->GardenPointer->increaseWeightsTotal(Weight);
}

void WOOD_CLASS::decreaseWeightsTotal(unsigned int Weight) {
    this->WeightsTotal -= Weight;
    if (this->GardenPointer != NULL)
        this->GardenPointer->decreaseWeightsTotal(Weight);
}

void WOOD_CLASS::increaseFruitsTotal(unsigned int Fruits) {
    this->FruitsTotal += Fruits;
    if (this->GardenPointer != NULL)
        this->GardenPointer->increaseFruitsTotal(Fruits);
}

void WOOD_CLASS::decreaseFruitsTotal() {
    this->FruitsTotal--;
    if (this->GardenPointer != NULL)
        this->GardenPointer->decreaseFruitsTotal();
}

void WOOD_CLASS::increaseBranchesTotal() {
    this->BranchesTotal++;
    if (this->GardenPointer != NULL)
        this->GardenPointer->increaseBranchesTotal();
}

void WOOD_CLASS::decreaseBranchesTotal() {
    this->BranchesTotal--;
    if (this->GardenPointer != NULL)
        this->GardenPointer->decreaseBranchesTotal();
}

BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS &object) {
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->Length = object.Length;
    this->WoodPointer = object.WoodPointer;
    if (object.FirstFruit == NULL) {
        this->FirstFruit = NULL;
        this->LastFruit = NULL;
    } else {
        Fruits *Temp = new Fruits;
        Fruits *Temp2 = object.FirstFruit;
        this->FirstFruit = Temp;
        while (Temp2) {
            Temp->FruitPointer = new FRUIT_CLASS(*Temp2->FruitPointer);
            Temp->FruitPointer->setBranchPointer(this);
            Temp->Length = Temp2->Length;
            FruitsTotal++;
            WeightsTotal += Temp->FruitPointer->getWeight();

            if (Temp2->NextFruit) {
                Temp->NextFruit = new Fruits;
                Temp = Temp->NextFruit;
            }
            LastFruit = Temp;
            Temp2 = Temp2->NextFruit;
        }
    }
}

void BRANCH_CLASS::setWoodPointer(WOOD_CLASS *WoodPointer) {
    this->WoodPointer = WoodPointer;
}

WOOD_CLASS::WOOD_CLASS(const WOOD_CLASS &object) {
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->Height = object.Height;
    if (object.FirstBranch == NULL) {
        this->FirstBranch = NULL;
        this->LastBranch = NULL;
    } else {
        Branches *Temp = new Branches;
        Branches *Temp2 = object.FirstBranch;
        this->FirstBranch = Temp;
        while (Temp2) {
            Temp->BranchPointer = new BRANCH_CLASS(*Temp2->BranchPointer);
            Temp->BranchPointer->setWoodPointer(this);
            Temp->Height = Temp2->Height;
            this->FruitsTotal += Temp->BranchPointer->getFruitsTotal();
            this->WeightsTotal += Temp->BranchPointer->getWeightsTotal();
            this->BranchesTotal++;
            if (Temp2->NextBranch) {
                Temp->NextBranch = new Branches;
                Temp = Temp->NextBranch;
            }
            LastBranch = Temp;
            Temp2 = Temp2->NextBranch;
        }
    }
}
