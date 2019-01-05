package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"reflect"
	"time"
)

type Weather struct {
	Time     string   `json:"time"`
	CityInfo CityInfo `json:"cityInfo"`
	Date     string   `json:"date"`
	Status   int      `json:"status"`
	Data     Data     `json:"data"`
}

type CityInfo struct {
	City       string `json:"city"`
	CityId     string `json:"cityId"`
	Parent     string `json:"parent"`
	UpdateTime string `json:"updateTime"`
}

type Data struct {
	Shidu    string      `json:"shidu"`
	Pm25     float64     `json:"pm25"`
	Pm10     float64     `json:"pm10"`
	Quality  string      `json:"quality"`
	Wendu    string      `json:"wendu"`
	Ganmao   string      `json:"ganmao"`
	Forecast []DetailDay `json:"forecast"`
}

type DetailDay struct {
	Sunrise string `json:"sunrise"`
	Sunset  string `json:"sunset"`
	High    string `json:"high"`
	Low     string `json:"low"`
	Ymd     string `json:"ymd"`
	Week    string `json:"week"`
	Fx      string `json:"fx"`
	Fl      string `json:"fl"`
	Type    string `json:"type"`
	Notice  string `json:"notice"`
}

func main() {
	var weather Weather
	// client 一个有超时的客户端
	client := &http.Client{
		Timeout: 20 * time.Second,
	}
	// 创建请求
	req, err := http.NewRequest("GET", "http://t.weather.sojson.com/api/weather/city/101270101", nil)
	if err != nil {
		log.Fatal(err)
	}
	req.Header.Set("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36")
	// 使用客户端进行请求并得到响应
	res, err := client.Do(req)
	if err != nil {
		log.Fatal(err)
	}
	defer res.Body.Close()
	// 使用解码对流数据进行分析
	decoderData := json.NewDecoder(res.Body)
	err = decoderData.Decode(&weather) // 指定容器, 将使用weather将得到的数据进行赋值, 将会直接改变变量
	if err != nil {
		log.Fatal(err)
	}
	fmt.Print("查看原始的流数据: ", res.Body, "\n\n")
	if weather.Status != 200 {
		log.Println("请求未成功.")
	}
	fmt.Println(reflect.TypeOf(weather))
	fmt.Printf("%+v\n", weather)
}
