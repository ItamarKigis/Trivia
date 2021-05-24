import requests
import sqlite3

def dataToDB(db,data):
    con = sqlite3.connect(db)
    cur = con.cursor()
    for question in data['results']:
        incorrect = question['incorrect_answers']
        cur.execute("""INSERT INTO QUESTIONS (DATA,CORRECT_ANSWER,ANS2,ANS3,ANS4) VALUES (?,?,?,?,?)""",
                    (question['question'], question['correct_answer'],
                     incorrect[0],
                     incorrect[1],
                     incorrect[2]))
    con.commit()
    con.close()

def getData(url):
    r = requests.get('https://opentdb.com/api.php?amount=10&category=11&difficulty=easy')
    return r.json()

def main():
    data = getData("https://opentdb.com/api.php?amount=10&category=11&difficulty=easy")
    print(data)
    dataToDB("Trivia/Trivia/DataBaseFile.db",data)


if __name__ == '__main__':
    main()
