import { defineConfig } from 'vitest/config'
import vue from '@vitejs/plugin-vue'
import tailwindcss from '@tailwindcss/vite'
import path from 'path'
import { fileURLToPath } from 'node:url'

const __dirname = path.dirname(fileURLToPath(import.meta.url))

/** Vite 7 + Vitest 4: один конфиг (см. https://vitest.dev/guide/#projects ) */
export default defineConfig({
  server: {
    port: 5173,
    host: true,
  },
  plugins: [vue(), tailwindcss()],
  resolve: {
    alias: {
      '@': path.resolve(__dirname, './src'),
    },
  },
  test: {
    globals: true,
    environment: 'node',
    include: ['src/**/*.test.ts'],
    // Windows: при неполной установке Vitest падает импорт из workers/forks.js (нет chunk base.*.js)
    pool: 'threads',
  },
})