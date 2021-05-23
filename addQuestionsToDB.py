import requests, sqlite3
import sqlite3

def dataToDB(db,data):
    con = sqlite3.connect(db)
    cur = con.cursor()
    cur.execute('''CREATE TABLE QUESTIONS IF NOT EXISTS (
                ID INT INCREMENT PRIMARY KEY,
                DATA TEXT NOT NULL,
                CORRECT_ANSWER TEXT NOT NULL,
                ANS2 TEXT NOT NULL,
                ANS3 TEXT NOT NULL,
                ANS4 TEXT NOT NULL)''')
    con.commit()
    for question in data['results']:
        cur.execute("""INSERT INTO QUESTIONS (DATA,CORRECT_ANSWER,ANS2,ANS3,ANS4) VALUES (?,?,?,?,?);""",
                    (question['question'], question['correct_answer'],
                     question['incorrect_answers'][0],
                     question['incorrect_answers'][1],
                     question['incorrect_answers'][2]))
    con.commit()
    con.close()

def getData(url):
    r = requests.get('https://opentdb.com/api.php?amount=10&category=11&difficulty=easy')
    return r.json()

def main():
    data = getData("https://opentdb.com/api.php?amount=10&category=11&difficulty=easy")
    dataToDB("Trivia/Trivia/DataBaseFile.db",data)


if __name__ == '__main__':
    main()
