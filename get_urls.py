import re


with open('E:/Git/Git/Hexo/public/baidusitemap.xml', 'r', encoding='utf8') as f:
    cont = f.read()


res = re.findall(r'<loc>(.*?)</loc>', cont)

with open('E:/Git/Git/Hexo/public/urls.txt', 'w', encoding='utf8') as f:
    for item in res:
        f.write("%s\n" % item.strip())