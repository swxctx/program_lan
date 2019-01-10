package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
)

func main() {
	// 路由规则
	http.HandleFunc("/hello", hello)
	http.HandleFunc("/oozgo", oozgoCon)
	//启动端口的监听
	err := http.ListenAndServe(":8080", nil)
	//异常处理
	if err != nil {
		log.Fatal(err)
	}
}

func hello(rsp http.ResponseWriter, req *http.Request) {
	io.WriteString(rsp, "hello")
}

type Context struct {
	Request  *http.Request
	Response http.ResponseWriter
}

func oozgoCon(rsp http.ResponseWriter, req *http.Request) {
	oozgo(&Context{
		Request:  req,
		Response: rsp,
	})
}

func oozgo(context *Context) {
	fmt.Fprint(context.Response, context.Request.Host)
}
