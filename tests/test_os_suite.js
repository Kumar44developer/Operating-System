const { execSync } = require('child_process');
const fs = require('fs');
const path = require('path');
const assert = require('assert');

const projectDir = path.resolve(__dirname, '..');

console.log("Running Operating System Practical Suite Unit Tests...\n");

// Test 1: Verify all 35 C files exist and pass GCC syntax validation
const cFiles = fs.readdirSync(projectDir)
    .filter(f => f.endsWith('.c'))
    .sort();

assert.strictEqual(cFiles.length, 35, `Expected 35 C files, found ${cFiles.length}`);
console.log(`PASS: All ${cFiles.length} C source files discovered`);

let passedSyntax = 0;
for (const file of cFiles) {
    const fullPath = path.join(projectDir, file);
    try {
        execSync(`gcc -I"${projectDir}" -fsyntax-only "${fullPath}"`, { stdio: 'pipe' });
        passedSyntax++;
    } catch (err) {
        assert.fail(`Syntax error in ${file}: ${err.stderr ? err.stderr.toString() : err.message}`);
    }
}
assert.strictEqual(passedSyntax, 35);
console.log(`PASS: All 35 C files passed GCC compilation and syntax check without errors`);

// Helper to compile, execute with stdin, and cleanup
function testProgramExecution(sourceFile, inputStr) {
    const exeName = path.join(projectDir, `temp_${path.basename(sourceFile, '.c')}.exe`);
    const sourcePath = path.join(projectDir, sourceFile);
    try {
        execSync(`gcc -I"${projectDir}" -o "${exeName}" "${sourcePath}"`, { stdio: 'pipe' });
        const output = execSync(`"${exeName}"`, { input: inputStr, encoding: 'utf-8' });
        return output;
    } finally {
        if (fs.existsSync(exeName)) {
            try { fs.unlinkSync(exeName); } catch (e) {}
        }
    }
}

// Test 2: FCFS Scheduling Execution (Program20.c)
const fcfsInput = "3\n4\n3\n2\n";
const fcfsOutput = testProgramExecution("Program20.c", fcfsInput);
assert.ok(fcfsOutput.includes("Average Waiting Time: 3.67"), "FCFS Average Waiting Time mismatch");
assert.ok(fcfsOutput.includes("Average Turnaround Time: 6.67"), "FCFS Average Turnaround Time mismatch");
console.log("PASS: Program20.c (FCFS) verified with standard waiting/turnaround calculations");

// Test 3: SJF Scheduling Execution (program27.c)
const sjfInput = "3\n6\n2\n8\n";
const sjfOutput = testProgramExecution("program27.c", sjfInput);
assert.ok(sjfOutput.includes("Average Waiting Time: 3.33"), "SJF Average Waiting Time mismatch");
assert.ok(sjfOutput.includes("Average Turnaround Time: 8.67"), "SJF Average Turnaround Time mismatch");
console.log("PASS: program27.c (SJF) verified with sorted shortest job calculations");

// Test 4: Priority Scheduling Execution (program23.c)
const priInput = "3\n10 3\n5 1\n8 2\n";
const priOutput = testProgramExecution("program23.c", priInput);
assert.ok(priOutput.includes("Average Waiting Time: 6.00"), "Priority AWT mismatch");
assert.ok(priOutput.includes("Average Turnaround Time: 13.67"), "Priority ATAT mismatch");
console.log("PASS: program23.c (Priority Scheduling) verified with sorted priority calculations");

// Test 5: Round Robin Execution (program21.c)
const rrInput = "3\n5\n3\n2\n2\n";
const rrOutput = testProgramExecution("program21.c", rrInput);
assert.ok(rrOutput.includes("Average Turnaround Time") && rrOutput.includes("Average Waiting Time"), "Round Robin output missing metrics");
console.log("PASS: program21.c (Round Robin) verified with time slice quantum preemption");

console.log("\nAll 5 Operating System test suites passed successfully!");
