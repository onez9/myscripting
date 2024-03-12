import io
import json
from zipfile import ZipFile



if __name__ == '__main__':
    buf = io.BytesIO()

    with ZipFile(buf, 'w') as fo:
        with io.BytesIO() as json_buf:
            data = json.dumps({'a': 1, 'b': 2})
            json_buf.write(data.encode())
            json_buf.seek(0)
            fo.writestr('1.json', json_buf.read())

