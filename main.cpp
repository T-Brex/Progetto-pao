#include <QApplication>
#include <QRadioButton>
#include "frontend/mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>                                                                                                                                                                                                                                                          Copy code






//#include <QMenuBar>
//#include <QMenu>
//#include <QAction>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //prova con Sensor
    QVector<Sensor*> s;
    Humidity *hum=new Humidity("hum");
    Termometer *term=new Termometer("term");
    s.push_front(hum);
    s.push_front(term);

    //prova con un solo sensore
    SensorPanel *airQ = new SensorPanel(AirQuality("airQ"));

    /*  Prova con sensorPanel*/
    QVector<SensorPanel*> sp;
    SensorPanel *ventoPanel= new SensorPanel(Wind("ven"));
    SensorPanel *polvPanel = new SensorPanel(Dust("polv"));
    sp.push_front(ventoPanel);
    sp.push_front(polvPanel);
    sp.push_front(airQ);





    /*
     *
     *
     * PROVA JSON

    std::ifstream file(" "); resou

    // Verifica se il file è stato aperto correttamente
    if (!file.is_open()) {
        std::cerr << "Impossibile aprire il file JSON\n";
        return 1;
    }

    // Carica il contenuto del file JSON
    json j;
    file >> j;

    // Chiudiamo il file
    file.close();

    // Otteniamo l'array degli utenti
    auto utenti_json = j["utenti"];

    // Creiamo un vettore di puntatori a Utente
    std::vector<Utente*> utenti;

    // Iteriamo sugli utenti JSON e creiamo gli oggetti Utente corrispondenti
    for (auto& utente_json : utenti_json) {
        int id = utente_json["id"];
        std::string nome = utente_json["nome"];
        std::string cognome = utente_json["cognome"];
        int eta = utente_json["eta"];
        std::string email = utente_json["email"];

        // Allochiamo un nuovo oggetto Utente sullo heap e aggiungiamolo al vettore
        Utente* nuovo_utente = new Utente(id, nome, cognome, eta, email);
        utenti.push_back(nuovo_utente);
    }

    // Stampiamo le informazioni sugli utenti
    for (const auto& utente : utenti) {
        std::cout << "ID: " << utente->id << std::endl;
        std::cout << "Nome: " << utente->nome << std::endl;
        std::cout << "Cognome: " << utente->cognome << std::endl;
        std::cout << "Età: " << utente->eta << std::endl;
        std::cout << "Email: " << utente->email << std::endl;
        std::cout << std::endl;
    }

    // Liberiamo la memoria allocata per gli oggetti Utente
    for (auto& utente : utenti) {
        delete utente;
    }
    */







     /*Prova con bottoni*/
    QWidget *b = new QWidget;
    QLayout* blayout = new QHBoxLayout(b);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    blayout->addWidget(button1);
    blayout->addWidget(button2);





    //Prova con sezioni
    QVector<QWidget *> frame;
    frame.push_front(SensorPanel::getSensorsWidget(sp));

    frame.push_front(airQ);




    MainWindow w(frame);



    //SearchMenu *sm=new SearchMenu();
    //MainWindow w(sm);
    w.setWindowTitle("Sensori");

    w.resize(1280, 1024);

    w.show();
    return a.exec();
}
