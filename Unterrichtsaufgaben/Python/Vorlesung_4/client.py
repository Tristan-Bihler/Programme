import sqlite3
verbindung = sqlite3.connect(r"Unterrichtsaufgaben\Python\Vorlesung_4\geburtstage.db")
zeiger = verbindung.cursor()

sql_anweisung = """
CREATE TABLE IF NOT EXISTS personen (
vorname VARCHAR(20), 
nachname VARCHAR(30), 
geburtstag DATE
);"""

zeiger.execute(sql_anweisung)

sql_anweisung = """
CREATE TABLE IF NOT EXISTS Essen (
name VARCHAR(20), 
herkunft VARCHAR(30),
gekauft_von VARCHAR(30), 
Ablaufdatum DATE
);"""

zeiger.execute(sql_anweisung)

sql_anweisung = """
INSERT INTO personen VALUES ('Johann Wolfgang von', 'Goethe', '28.8.1749')
"""

zeiger.execute(sql_anweisung)

for i in range(10000):
    sql_anweisung = f"INSERT INTO Essen VALUES ('Annanas', 'Brasilien', 'Edeka', '{i}')"
    zeiger.execute(sql_anweisung)

zeiger.execute("SELECT * FROM Essen")

inhalt = zeiger.fetchall()
print(inhalt)

verbindung.commit()
verbindung.close()