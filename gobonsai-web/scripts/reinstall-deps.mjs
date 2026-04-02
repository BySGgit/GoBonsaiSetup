/**
 * Чистая переустановка при битом node_modules / кэше npm / EPERM.
 * Перед запуском: закройте `npm run dev`, IDE не должна держать файлы в node_modules.
 */
import { rmSync } from 'node:fs';
import { spawnSync } from 'node:child_process';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const nm = path.join(root, 'node_modules');

console.log('Removing node_modules …');
try {
  rmSync(nm, { recursive: true, force: true });
} catch (e) {
  console.error('Не удалось удалить node_modules (закройте процессы, использующие папку):', e.message);
  process.exit(1);
}

const run = (args) => {
  const r = spawnSync('npm', args, { stdio: 'inherit', cwd: root, shell: true });
  if (r.status !== 0) process.exit(r.status ?? 1);
};

run(['cache', 'clean', '--force']);
run(['install']);
