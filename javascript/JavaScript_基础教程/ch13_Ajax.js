// 可适用于django csrf验证的异步

var xhr = new XMLHttpRequest()
xhr.onreadystatechange = function() {
    if (xhr.readyState == 4 && xhr.status == 200){
        console.log(JSON.parse(xhr.responseText))
    }
}
xhr.open("POST", "{% url 'index:main_page' %}", true)
xhr.setRequestHeader("content-type", "application/json;charset=utf-8")
xhr.setRequestHeader("X-CSRFToken", '{{ csrf_token }}')
xhr.send("index_ptr=" + index_ptr + "&interval_days=" + interval_days)