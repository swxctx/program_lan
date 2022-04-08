<template>
  <div>
    <h3>注册</h3>
    <input type="text" placeholder="请输入用户名" v-model="username">
    <input type="password" placeholder="请输入密码" v-model="password">
    <button v-on:click="register">注册</button>
  </div>
</template>
<script>
export default{
    data() {
        return {
            username: '',
            password: '',
        }
    },
    methods:{
        register() {
            // console.log(username);
            alert("用户名: " + this.username + "\n密码：" + this.password);
        }
    }
}
</script>