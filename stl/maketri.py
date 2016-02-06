import teapot
print len(teapot.triangles)
for tr in teapot.triangles:
    for vec in tr:
        print vec[0], vec[1], vec[2]
