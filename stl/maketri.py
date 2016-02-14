import temp
print len(temp.triangles)
for tr in temp.triangles:
    for vec in tr:
        print vec[0], vec[1], vec[2]
