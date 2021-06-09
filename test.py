import requests
url = "https://api.weixin.qq.com/card/invoice/scantitle?access_token={access_token}"
data = {"scan_text" : "https://w.url.cn/s/AN6Kyvi"}
res = requests.post(url=url,data=data)
print(res.text)