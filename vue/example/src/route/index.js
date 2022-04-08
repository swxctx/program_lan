import { createRouter,createWebHashHistory} from "vue-router";

const home = () => import("../components/Home")
const register = () => import("../components/Register")

const routes = [
  { path: "/", redirect: "/home" },
  {
    path: "/home",
    name: "home",
    component: home
  },
  {
    path: "/register",
    name: "register",
    component: register
  }
]

export const router = createRouter({
    history: createWebHashHistory(),
    routes: routes
  })