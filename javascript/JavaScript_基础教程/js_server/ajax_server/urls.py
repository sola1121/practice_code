from django.urls import path

from . import views

app_name = "ajax_server"

urlpatterns = [
    path("index/", views.index, name="index"),
    path("get_data", views.back_data, name="get_data"),
]