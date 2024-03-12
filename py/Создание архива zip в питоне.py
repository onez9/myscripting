import asyncio
from zipfile import ZipFile
import time
# zipObj = ZipFile('image_arhive.zip', 'w')
# # Add multiple files to the zip
# for item in array_zip:
#   zipObj.write(item)
# # close the Zip File
# zipObj.close()

async def create_archive(array_zip):

  async with ZipFile('video_arhive.zip', 'w') as zof:
    for item in array_zip:
      await zof.write(item)

async def main():
  arr = ['1.jpg', '2.jpg', '3.jpg']
  await create_archive(arr)

asyncio.run(main())
# time.sleep(123)
