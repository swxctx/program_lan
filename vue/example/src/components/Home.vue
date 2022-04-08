<template>
  <div>
      <h3>欢迎您</h3>
      <button @click="toRegister">去注册</button>
  </div>
</template>
<script>
import { useRouter } from 'vue-router'
export default{
    setup () {
      const router = useRouter()
      const toRegister = (() => {
        router.push({
          name: 'register'
        })
      })
      return {
        toRegister
      }
    },
}
</script>