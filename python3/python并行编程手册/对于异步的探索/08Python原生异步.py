import asyncio
import aiohttp


host = "http://example.com"
urls_todo = set(['/', "/1", "/2", "/3", "/4", "/5", "/6", "/7", "/8", "/9"])

loop = asyncio.get_event_loop()


async def fetch(url):
    async with aiohttp.ClientSession(loop=loop) as session:
        response = await response.read()
        return response


if __name__ == "__main__":
    import time

    start = time.time()
    tasks = [fetch(host + url) for url in urls_todo]
    loop.run_until_complete(asyncio.gether(*tasks))
    print(time.time()-start)
