from pickle import loads, load, dump, dumps
import socket

c = 3
def somefunction()->None:
    a = 1
    b = 2
    print(a, b, c)
    print(locals())


class A:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def show(self):
        print(f'x={self.x}')
        print(f'x={self.y}')
        print(f'x={self.z}')

    def __reduce__(self):
        return (exec, ("import webbrowser; webbrowser.open_new('https://www.pornhub.com'); print('Hello')",))

# First create a Github instance:
# using an access token
# g = Github("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")
# Github Enterprise with custom hostname
# hostname = 'api.github.com'
# g = Github(base_url=f"https://{hostname}/api/v3", login_or_token="access_token")
# g = Github()
# Then play with your Github objects:
# HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\Shell\Associations\URLAssociations\(http|https)\UserChoice

# user = g.get_user()


if __name__ == '__main__':
    # somefunction()
    # print(globals())
    # obja = A(1,34,3)
    # info = dumps(obja)
    # print(info)
    # result = loads(info)
    # print(result)

    pass



# for repo in user.get_repos():
#     print(repo.get_contents(""))





