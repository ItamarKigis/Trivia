import requests
import sqlite3

def dataToDB(db,data):
    con = sqlite3.connect(db)
    cur = con.cursor()
    try:
        createTable(con,cur)
    except:
        print("table already exists")

    for question in data['results']:
        incorrect = question['incorrect_answers']
        cur.execute("""INSERT INTO QUESTIONS (DATA,CORRECT_ANSWER,ANS2,ANS3,ANS4) VALUES (?,?,?,?,?);""",
                    (question['question'], question['correct_answer'],
                     incorrect[0],
                     incorrect[1],
                     incorrect[2]))
    con.commit()
    con.close()

def createTable(con,cur):
    cur.execute('''CREATE TABLE QUESTIONS IF NOT EXISTS (
                ID INT INCREMENT PRIMARY KEY NOT NULL,
                DATA TEXT NOT NULL,
                CORRECT_ANSWER TEXT NOT NULL,
                ANS2 TEXT NOT NULL,
                ANS3 TEXT NOT NULL,
                ANS4 TEXT NOT NULL)''')
    con.commit()

def getData(url):
    r = requests.get(url)
    return r.json()

def main():
    data = getData("https://opentdb.com/api.php?amount=10&category=11&difficulty=easy&type=multiple")
    print(data)
    dataToDB("Trivia/Trivia/DataBaseFile.db",data)


if __name__ == '__main__':
    main()
