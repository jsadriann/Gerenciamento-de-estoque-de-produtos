import json
class CheckLogin:
    def __init__(self,login,password):
        self.login = login
        self.password = password
    def tojson(self):
        return json.dumps(self.__dict__)