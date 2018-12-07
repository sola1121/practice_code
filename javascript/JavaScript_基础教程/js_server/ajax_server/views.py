from django.shortcuts import render
from django.http import JsonResponse, FileResponse, StreamingHttpResponse
# Create your views here.

def index(request):
    return render(request, "index.html")


def back_data(request):
    if request.method == "GET":
        return render(request, "ajax_test_page.html")
    if request.method == "POST":
        a_dict = {"aaa": 111, "bbb": 222, "ccc": 333, "ddd": 444, "eee": 555}
        a_list = [11111, 22222, 33333, 44444, 55555]
        a_file = open("../manage.py", "rb")
        return FileResponse(a_file, as_attachment=True)