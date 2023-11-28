# Usage

* Get

```py
import requests
get_param = {"key": "value"}
r= requests.get("http://127.0.0.1:8080/api", params=get_param)
```

* POST

```py
import requests
post_data = {"key": "value"}
# Raw data
r= requests.post("http://127.0.0.1:8080/api", data=post_data)
# json type
r= requests.post("http://127.0.0.1:8080/api", json=post_data)
```

* With header (if need to login)

```py
import requests
# Authorization
header_data = {"Authorization": "myauth"}
post_data = {"key": "value"}
r = requests.post("http://127.0.0.1:8080/api", header=header_data, json=post_data)
# Cookie
cookie_data = {"my_cookie_name": "This is cookie"}
r = requests.get("http://127.0.0.1:8080/api", cookie=cookie_data)
```

* Return request result

```py
import requests
r= requests.get("http://127.0.0.1:8080/api")
# Check return code is 200 or not
if r.status_code == reqests.codes.ok:
    # Print HTML output
    print(r.text)
    # If the output is json, print json
    print(r.json())
```

# Useful tips

* Add timeout

```py
# Wait 3 sec
r = requests.get('http://google.com', timeout=3)
```

* Ignore invalid certificate

```py
r = requests.get('https://127.0.0.1:8080/api', verify=False)
```
