# sqlalchemy quick start
# https://docs.sqlalchemy.org/en/rel_1_2/orm/tutorial.html

import sqlalchemy

db_engine = sqlalchemy.create_engine("mysql+pymysql://leimilia:leimilia@localhost/employees?charset=utf8mb4")

results = db_engine.execute("select * from departments limit 10")
for result in results.fetchall():
    print(result)
