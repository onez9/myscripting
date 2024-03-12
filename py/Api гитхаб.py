from github import Github

# First create a Github instance:
# using an access token
g = Github("")
# Github Enterprise with custom hostname
# hostname = 'api.github.com'
# g = Github(base_url=f"https://{hostname}/api/v3", login_or_token="access_token")
# g = Github()
# Then play with your Github objects:

user = g.get_user()

for repo in user.get_repos():
    print(repo.get_contents(""))





