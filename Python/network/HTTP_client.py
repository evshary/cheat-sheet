import http.client

# Use HTTPConnection if the connection is HTTP
conn = http.client.HTTPSConnection("www.python.org")
conn.request("GET", "/")
resp = conn.getresponse()
print(resp.status, resp.reason)
data1 = resp.read()
print(data1)