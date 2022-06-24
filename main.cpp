#include <iostream>
#include<cstdlib>
#include <string>
#include <vector>

using namespace std;

class Human 
{
public:   
 Human()
 {
    strength = rand() % 5 + 1;
    agility = rand() % 5 + 1;
    gender = rand() %2? "male" : "female";
    name = namebib[rand() %20];
    endurance = 100;
    satiety = 100;
    profession = "unknow";
 }
 string GetResources() const
 {
    string res;
    res = name  + " have " + to_string(resources) + " resource point";
    return res;
 }
 void Eating()
 {  
    cout << name << " try eat: ";
    if(satiety == 100)
        cout << "Not hungry" << endl;
    if(resources <= 0)
        cout << "No resources for eating" << endl;
    else if(satiety < 100)
    {
        satiety += 20;
        resources -= 1;
        cout << "Ate" << endl;
    }
 } 
 void Sleping()
 {
    cout << name << " sleping" << endl;
    if(endurance < 100)
        endurance += 20;
 }
 void Workout()
 {
    cout << name << " try  workout: ";
    if(satiety <= 0)
        cout << "Hungry" << endl;
    if(endurance <= 0)
        cout << "Need to sleep" << endl;
    if(resources <= 0)
        cout << "No resources for workout" << endl;
    if(satiety > 0 && resources > 0 && endurance > 0)
    {
        if(gender == "male" && strength < 10  && agility < 8)
            rand() %2?
            strength += 1  : agility += 1;
        if(gender == "female" && strength < 8  && agility < 10)
            rand() %2?
            strength += 1  : agility += 1;
        resources -= 1;
        satiety -= 20;
        endurance -= 20;
        cout << "Workout successful" << endl;
    }

 }
 virtual void Hunting()
 {
     
 }
 virtual void Fishing(){}
 virtual void Gathering(){}
 virtual string Info() const
 { 
    string all;
    all = "Tribe member name is " + name + "| gender is " + gender + "| strength: " + to_string(strength) + "| agility: " + to_string(agility) 
        + "| stamina: " + to_string(endurance) + "| satiety: " + to_string(satiety) + "| profession is " + profession;
    return all;
 }
protected:
 string namebib[20] = {"Opale Haf", "Lone Al", "Rukoli Noni", "Kaza Astore", "Luko Grate", "Joji Uy", "Guyo Jap", "Fran Dude", "Io Troh", "klar Ko",
                       "Log Tog", "Biblo Bag", "Momi Ujino", "Fed Drack", "Gdb Onilene", "Astro Simple", " Polo Res", "Ucro Angel", "Nabe Apon", "Axo Xco"};
 string name, gender, profession;
 int strength, agility, endurance, satiety, resources = 1;
}; 

class Hunter : public Human
{
public: 
 Hunter() : Human()
 {
    profession = "Hunter";
    huntingskill = 1;
 }
 void Hunting() override
 {
    int d = huntingskill + agility + strength;
    cout << name << " try hunting: ";
    if(satiety <= 0)
        cout << "Hungry" << endl;
    if(endurance <= 0)
        cout << "Need to sleep" << endl;
    if(satiety > 0 && endurance > 0)
    {
        if(d <= 10)
        {
            cout << "hunting gave us 1 resource point" << endl;
            resources += 1;
            satiety -= 20;
            endurance -= 20;
        }
        else if(d <= 20 && d > 10 )
        {
            cout << "hunting gave us 2 resource point" << endl;
            resources += 2;
            satiety -= 20;
            endurance -= 20;
        }
        else if(d <= 50 && d > 20)
        {
            cout << "hunting gave us 3 resource point" << endl;
            resources += 3;
            satiety -= 20;
            endurance -= 20;
        }
        if(huntingskill < 10)
            huntingskill += 1;
    }
 }
 string Info() const override
 {
    string all;
    all = Human::Info() + "| huntingskill: " + to_string(huntingskill);
    return all;
 }
private:
 int huntingskill;
};

class Fisherman : public Human
{
public: 
 Fisherman() : Human()
 {
    profession = "Fisherman";
    fishingskill = 1;
 }
 void Fishing() override
 {
    int g = fishingskill + 2*agility + strength/2;
    cout << name <<  " try fishing: ";
    if(satiety <= 0)
        cout << "Hungry" << endl;
    if(endurance <= 0)
        cout << "Need to sleep" << endl;
    if(satiety > 0 && endurance > 0)
    {
        if(g <= 10)
        {
            cout << "fishing gave us 1 resource point" << endl;
            resources += 1;
            satiety -= 20;
            endurance -= 20;
        }
        else if(10 < g && g <= 20)
        {
            cout << "fishing gave us 2 resource point" << endl;
            resources += 2;
            satiety -= 20;
            endurance -= 20;
        }
        else if(20 < g && g <= 50)
        {
            cout << "fishing gave us 3 resource point" << endl;
            resources += 3;
            satiety -= 20;
            endurance -= 20;
        }
        if(fishingskill < 10)
            fishingskill += 1;
    }
 }
 string Info() const override
 {
    string all;
    all = Human::Info() + "| fishingskill: " + to_string(fishingskill);
    return all;
 }
private:
 int fishingskill;
};

class Collector : public Human
{
public: 
 Collector() : Human()
 {
    profession = "Collector";
    gatheringskill = 1;
 }
 void Gathering() override
 {
    int k = gatheringskill + 3*agility + strength/3;
    cout << name << " try gathering: ";
    if(satiety <= 0)
        cout << "Hungry" << endl;
    if(endurance <= 0)
        cout << "Need to sleep" << endl;
    if(satiety > 0 && endurance > 0)
    {
        if(k <= 10)
        {
            cout << "gathering gave us 1 resource point" << endl;
            resources += 1;
            satiety -= 20;
            endurance -= 20;
        }
        else if(k <= 20 && k > 10)
        {
            cout << "gathering gave us 2 resource point" << endl;
            resources += 2;
            satiety -= 20;
            endurance -= 20;
        }
        else if(k > 20 && k <= 50)
        {
            cout << "gathering gave us 3 resource point" << endl;
            resources += 3;
            satiety -= 20;
            endurance -= 20;
        }
        if(gatheringskill < 10)
            gatheringskill += 1;
    }
 }
 string Info() const override
 {
    string all;
    all = Human::Info() + "| gatheringskill: " + to_string(gatheringskill);
    return all;
 }
private:
 int gatheringskill;
};

class HumanSystem
{
private:
	vector <Human*> human;
public:
	~HumanSystem();
	void menu();
	void CreateTribe(int num);
	void Info();
    void GetResources();
    void Eat();
    void Sleep();
    void Workout();
    void Hunting();
    void Fishing();
    void Gathering();
};

HumanSystem::~HumanSystem()
{
	for (unsigned i=0;i<human.size();i++)
		delete human[i];
}

void HumanSystem::menu()
{
	char c;
	int num;
	unsigned number;
	do
	{
	cout << "A tribe can no more than 20 members and no less than 5" << endl;
            cout << "Enter the number of tribe members: ";
            cin >> num;
            try
            {
                if(num < 5)
                    throw "NO less than 5";
                if(num >20)
                    throw "NO more than 20";
            }
            catch (const char* exception)
            {
                cout << "Error: " << exception << endl;
                num = 0;
            }
			CreateTribe(num);
	}
	while (num == 0);
	do
	{
		cout << "1. Information about tribe" << endl;
		cout << "2. Tribe resources points"  << endl;
		cout << "3. Humans goes to eat"  << endl;
		cout << "4. Humans goes to sleep"  << endl;
		cout << "5. Humans goes to workout"  << endl;
		cout << "6. Humans goes to hunting"  << endl;
		cout << "7. Humans goes to fishing"  << endl;
		cout << "8. Humans goes to gathering"  << endl;
		cout << "0. Exit" <<endl;
		cin >> c;
        
		switch (c)
		{
		case '1':
			Info();
			break;
		case '2':
			GetResources();
			break;
		case '3':
				Eat();
				break;
		case '4':
			Sleep();
			break;
		case '5':
			Workout();
			break;
		case '6':
			Hunting();
			break;
		case '7':
			Fishing();
			break;
		case '8':
			Gathering();
			break;
		}
	}
	while (c!='0');
}

void HumanSystem::CreateTribe(int num)
{
    int c = num/2;
    int f = num/3;
    int h = num - c - f;
    for(int p = 0; p < c; p++)
	    human.push_back(new Collector());
    for(int p = 0; p < f; p++)
	    human.push_back(new Fisherman());
    for(int p = 0; p < h; p++)
	    human.push_back(new Hunter());
}

void HumanSystem::Info()
{
	for (unsigned i=0;i<human.size();i++)
		cout << human[i]-> Info() << endl;
}

void HumanSystem::GetResources()
{
    for (unsigned i=0;i<human.size();i++)
		cout << human[i]-> GetResources() << endl;
}

void HumanSystem::Eat()
{
	for (unsigned i=0;i<human.size();i++)
		 human[i]->Eating();
}

void HumanSystem::Sleep()
{
	for (unsigned i=0;i<human.size();i++)
		human[i]-> Sleping();
}
void HumanSystem::Workout()
{
	for (unsigned i=0;i<human.size();i++)
		human[i]-> Workout();
}
void HumanSystem::Hunting()
{
	for (unsigned i=0;i<human.size();i++)
		human[i]-> Hunting();
}

void HumanSystem::Fishing()
{
	for (unsigned i=0;i<human.size();i++)
		human[i]-> Fishing();
}

void HumanSystem::Gathering()
{
	for (unsigned i=0;i<human.size();i++)
		human[i]-> Gathering();
}

int main()
{
    srand(time(nullptr));
    HumanSystem tribe;
	tribe.menu(); 
	
    return 0;
}
