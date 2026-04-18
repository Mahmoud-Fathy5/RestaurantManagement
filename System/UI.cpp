//UI.cpp
//Author: Mahmoud Taha Date[13/4/2026]

#include "UI.h"


UI::UI()
{
}

UI::~UI()
{
}

string UI::readInputFileName()
{
    cout << "Enter the input file name: ";
    string fileName;
    cin >> fileName;
    cout<< endl;
    return fileName+".txt";

}

void UI::readOutputFileName(string s)
{
    cout<<"The Output File Name is :"<<s<<endl;
}

void UI::readMode()
{
	int mode;
    cout << "======================================== Restaurant Management System ========================================" << endl;
    cout << "Please select the program mode:" << endl;
    cout << "1.Silent" << endl;
    cout << "2.Interactive" << endl;
    cout << "Enter your choice 1 or 2"<<endl;
    cin >> mode;
    while (mode != 1 && mode != 2) {
        cout << "Invalid input, please enter 1 or 2";
        cout << "1.Silent" << endl;
        cout << "2.Interactive" << endl;
    }
    m_mode = (mode == 1) ? SILENT : INTERACTIVE;
    

}

void UI::printScreen(int currentTimeStep,
    LinkedQueue<Action*>& actionsList,
    LinkedQueue<Order*>& pendingDineInGrilledOrderList,
    LinkedQueue<Order*>& pendingDineInNormalOrderList,
    LinkedQueue<Order*>& pendingTakeAwayOrderList,
    LinkedQueue<Order*>& pendingDeliveryDineInNormalOrderList,
    DerivedQueue& pendingDeliveryColdOrders,
    priQueue<Order*>& pendingDeliveryGrilledOrders,
    LinkedQueue<Chef*>& freeSpecialChef,
    LinkedQueue<Chef*>& freeNormalChef,
    ArrayStack<Order*>& cancelledOrders,
    ArrayStack<Order*>& finishedOrders,
    CookingOrders& cookingOrders,
    LinkedQueue<Order*>& readyTakeAwayOrder,
    DerivedQueue& readyDeliveryOrder,
    LinkedQueue<Order*>& readyDineInOrder,
    priQueue<Order*>& inServiceOrder,
    priQueue<Scooter*>& freeScooters,
    priQueue<Scooter*>& backScooters,
    LinkedQueue<Scooter*>& maintenanceScooter,
    FitTables& freeTables,
    FitTables& busySharable,
    FitTables& busyNoShare)
{
    cout << "Current Timestep:" << currentTimeStep <<endl;
    cout << "=============== Actions List ================"<<endl;
    cout << actionsList.getCount() << "actions remaining:";
    actionsList.print();
    cout << endl;

    cout << "—------------- Pending Orders IDs —---------------------" << endl;
    cout << pendingDineInGrilledOrderList.getCount() << " ODG ";
    pendingDineInGrilledOrderList.print();
    cout << endl;
    cout << pendingDineInNormalOrderList.getCount() << " ODN ";
    pendingDineInNormalOrderList.print();
    cout << endl;
    cout << pendingTakeAwayOrderList.getCount() << " OT ";
    pendingTakeAwayOrderList.print();
    cout << endl;
    cout << pendingDeliveryColdOrders.getCount() << " OVC ";
    pendingDeliveryColdOrders.print();
    cout << endl;
    cout << pendingDeliveryGrilledOrders.getCount() << " OVG ";
    pendingDeliveryGrilledOrders.print();
    cout << endl;
    cout << pendingDeliveryDineInNormalOrderList.getCount() << " OVN ";
    pendingDeliveryDineInNormalOrderList.print();
    cout << endl;


    cout << "—------------- Available chefs IDs —----------------------" << endl;
    cout << freeSpecialChef.getCount() <<" CS : ";
    freeSpecialChef.print();
    cout << endl;
    cout << freeNormalChef.getCount() <<" CN : ";
    freeNormalChef.print();
    cout << endl;


    cout << "—------------- Cooking orders [Orders ID, chef ID] —---------------------" << endl;
    cout <<cookingOrders.getCount()<<" cooking orders: [";
    cookingOrders.print();
    cout << "]";

    cout << "—------------- Ready Orders IDs —---------------------" << endl;
    cout << readyTakeAwayOrder.getCount()<< " OT ";
    readyTakeAwayOrder.print();
    cout << endl;
    cout << readyDeliveryOrder.getCount() << " OV ";
    readyTakeAwayOrder.print();
    cout << endl;
    cout << readyDineInOrder.getCount() << " OD ";
    readyTakeAwayOrder.print();
    cout << endl;


    cout << "—------------- Available scooters IDs —----------------------" << endl;
    cout << freeScooters.getCount() << " Scooters : ";
    freeScooters.print();
    cout << endl;

   
    cout<< "—------------ - Available tables[ID, capacity, free seats] —----------------------"<<endl;
    cout << freeTables.getCount()+busySharable.getCount()<<" tables";
    busySharable.print();
    cout << endl;
    freeTables.print();
    cout << endl;
    cout << "—------------- In-Service orders [order ID, scooter/Table ID] --—---------------------" << endl;
    cout << inServiceOrder.getCount()<<" Orders: ";
    inServiceOrder.print();
    cout << endl;


    cout << "—------------- In-maintainance scooters IDs ----------------------" <<endl;
    cout << maintenanceScooter.getCount() << " scooters: ";
    maintenanceScooter.print();
    cout << endl;

    cout << "—------------  Scooters Back to Restaurant IDs----------------------" << endl;
    cout << backScooters.getCount() << " scooters: ";
    backScooters.print();
    cout << endl;

    cout << "—------------- Cancelled Orders IDs ----------------------" << endl;
    cout << cancelledOrders.getCount() << " Cancelled: ";
    cancelledOrders.print();
    cout << endl;

    cout << "—------------- Finished orders IDs----------------------------" << endl;
    cout << finishedOrders.getCount() << " Finshed: ";
    finishedOrders.print();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !" << endl;

    //Clear the input buffer and wait for the user to   press any  key
    cin.ignore();
    cin.get();
}
