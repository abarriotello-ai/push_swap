#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Check if push_swap exists
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap executable not found!${NC}"
    echo -e "${YELLOW}Run 'make' first.${NC}"
    exit 1
fi

# Check if checker exists (optional)
CHECKER=""
if [ -f "./checker_OS" ]; then
    CHECKER="./checker_OS"
elif [ -f "./checker" ]; then
    CHECKER="./checker"
fi

echo -e "${BLUE}╔════════════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║        PUSH_SWAP COMPREHENSIVE BENCHMARK TESTS             ║${NC}"
echo -e "${BLUE}╔════════════════════════════════════════════════════════════╗${NC}"
echo ""

# ============================================================================
# TEST 1: 3 NUMBERS (Target: ≤ 3 operations)
# ============================================================================

echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}TEST 1: Sorting 3 Numbers (Target: ≤ 3 operations)${NC}"
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

# All 6 permutations of [1, 2, 3]
three_tests=(
    "1 2 3"
    "1 3 2"
    "2 1 3"
    "2 3 1"
    "3 1 2"
    "3 2 1"
)

three_max=0
three_total=0
three_failed=0

for test in "${three_tests[@]}"; do
    ops=$(./push_swap $test | wc -l)
    three_total=$((three_total + ops))
    
    if [ "$ops" -gt "$three_max" ]; then
        three_max=$ops
    fi
    
    echo -n "  [$test] → $ops ops "
    
    if [ "$ops" -le 3 ]; then
        echo -e "${GREEN}✓${NC}"
    else
        echo -e "${RED}✗ (exceeded 3)${NC}"
        three_failed=$((three_failed + 1))
    fi
    
    # Verify with checker if available
    if [ -n "$CHECKER" ]; then
        result=$(./push_swap $test | $CHECKER $test 2>&1)
        if [[ "$result" != "OK" ]]; then
            echo -e "    ${RED}⚠ CHECKER FAILED: Not sorted correctly!${NC}"
            three_failed=$((three_failed + 1))
        fi
    fi
done

three_avg=$((three_total / 6))
echo ""
echo -e "  Average: ${YELLOW}$three_avg${NC} ops"
echo -e "  Maximum: ${YELLOW}$three_max${NC} ops"
if [ $three_failed -eq 0 ]; then
    echo -e "  Result: ${GREEN}✓ ALL PASSED${NC}"
else
    echo -e "  Result: ${RED}✗ $three_failed FAILED${NC}"
fi
echo ""

# ============================================================================
# TEST 2: 5 NUMBERS (Target: ≤ 12 operations)
# ============================================================================

echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}TEST 2: Sorting 5 Numbers (Target: ≤ 12 operations)${NC}"
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

five_max=0
five_total=0
five_failed=0
five_count=10

for i in $(seq 1 $five_count); do
    # Generate 5 unique random numbers
    numbers=$(shuf -i 0-100 -n 5 | tr '\n' ' ')
    ops=$(./push_swap $numbers | wc -l)
    five_total=$((five_total + ops))
    
    if [ "$ops" -gt "$five_max" ]; then
        five_max=$ops
    fi
    
    echo -n "  Test $i: $ops ops "
    
    if [ "$ops" -le 12 ]; then
        echo -e "${GREEN}✓${NC}"
    else
        echo -e "${RED}✗ (exceeded 12)${NC}"
        five_failed=$((five_failed + 1))
    fi
    
    # Verify with checker
    if [ -n "$CHECKER" ]; then
        result=$(./push_swap $numbers | $CHECKER $numbers 2>&1)
        if [[ "$result" != "OK" ]]; then
            echo -e "    ${RED}⚠ CHECKER FAILED: Numbers: $numbers${NC}"
            five_failed=$((five_failed + 1))
        fi
    fi
done

five_avg=$((five_total / five_count))
echo ""
echo -e "  Average: ${YELLOW}$five_avg${NC} ops"
echo -e "  Maximum: ${YELLOW}$five_max${NC} ops"
if [ $five_failed -eq 0 ]; then
    echo -e "  Result: ${GREEN}✓ ALL PASSED${NC}"
else
    echo -e "  Result: ${RED}✗ $five_failed FAILED${NC}"
fi
echo ""

# ============================================================================
# TEST 3: 100 NUMBERS (Target: < 700 for 100%, < 1100 for 80%)
# ============================================================================

echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}TEST 3: Sorting 100 Numbers${NC}"
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "  ${YELLOW}100% Grade: < 700 operations${NC}"
echo -e "  ${YELLOW} 80% Grade: < 1100 operations${NC}"
echo ""

hundred_max=0
hundred_min=999999
hundred_total=0
hundred_failed=0
hundred_count=10

echo "  Running $hundred_count tests with 100 random numbers..."
echo ""

for i in $(seq 1 $hundred_count); do
    numbers=$(shuf -i 0-5000 -n 100 | tr '\n' ' ')
    ops=$(./push_swap $numbers | wc -l)
    hundred_total=$((hundred_total + ops))
    
    if [ "$ops" -gt "$hundred_max" ]; then
        hundred_max=$ops
    fi
    if [ "$ops" -lt "$hundred_min" ]; then
        hundred_min=$ops
    fi
    
    echo -n "  Test $i: $ops ops "
    
    if [ "$ops" -lt 700 ]; then
        echo -e "${GREEN}✓ Excellent (100%)${NC}"
    elif [ "$ops" -lt 900 ]; then
        echo -e "${GREEN}✓ Good${NC}"
    elif [ "$ops" -lt 1100 ]; then
        echo -e "${YELLOW}✓ Pass (80%)${NC}"
    else
        echo -e "${RED}✗ Fail${NC}"
        hundred_failed=$((hundred_failed + 1))
    fi
    
    # Verify with checker (only if available, to save time)
    if [ -n "$CHECKER" ] && [ $((i % 3)) -eq 0 ]; then
        result=$(./push_swap $numbers | $CHECKER $numbers 2>&1)
        if [[ "$result" != "OK" ]]; then
            echo -e "    ${RED}⚠ CHECKER FAILED${NC}"
            hundred_failed=$((hundred_failed + 1))
        fi
    fi
done

hundred_avg=$((hundred_total / hundred_count))
echo ""
echo -e "  ${BLUE}Statistics:${NC}"
echo -e "  ├─ Average:  ${YELLOW}$hundred_avg${NC} ops"
echo -e "  ├─ Minimum:  ${YELLOW}$hundred_min${NC} ops"
echo -e "  └─ Maximum:  ${YELLOW}$hundred_max${NC} ops"
echo ""

if [ "$hundred_avg" -lt 700 ]; then
    echo -e "  Result: ${GREEN}✓ EXCELLENT - 100% Grade${NC}"
elif [ "$hundred_avg" -lt 900 ]; then
    echo -e "  Result: ${GREEN}✓ GOOD - Passing with margin${NC}"
elif [ "$hundred_avg" -lt 1100 ]; then
    echo -e "  Result: ${YELLOW}✓ PASS - 80% Grade${NC}"
else
    echo -e "  Result: ${RED}✗ FAIL - Above 1100 average${NC}"
fi
echo ""

# ============================================================================
# TEST 4: 500 NUMBERS (Target: < 5500 for 100%, < 8500 for 80%)
# ============================================================================

echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${MAGENTA}TEST 4: Sorting 500 Numbers${NC}"
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "  ${YELLOW}100% Grade: < 5500 operations${NC}"
echo -e "  ${YELLOW} 80% Grade: < 8500 operations${NC}"
echo ""

fiveh_max=0
fiveh_min=999999
fiveh_total=0
fiveh_failed=0
fiveh_count=5

echo "  Running $fiveh_count tests with 500 random numbers..."
echo "  ${YELLOW}(This may take a moment...)${NC}"
echo ""

for i in $(seq 1 $fiveh_count); do
    numbers=$(shuf -i 0-10000 -n 500 | tr '\n' ' ')
    ops=$(./push_swap $numbers | wc -l)
    fiveh_total=$((fiveh_total + ops))
    
    if [ "$ops" -gt "$fiveh_max" ]; then
        fiveh_max=$ops
    fi
    if [ "$ops" -lt "$fiveh_min" ]; then
        fiveh_min=$ops
    fi
    
    echo -n "  Test $i: $ops ops "
    
    if [ "$ops" -lt 5500 ]; then
        echo -e "${GREEN}✓ Excellent (100%)${NC}"
    elif [ "$ops" -lt 7000 ]; then
        echo -e "${GREEN}✓ Good${NC}"
    elif [ "$ops" -lt 8500 ]; then
        echo -e "${YELLOW}✓ Pass (80%)${NC}"
    else
        echo -e "${RED}✗ Fail${NC}"
        fiveh_failed=$((fiveh_failed + 1))
    fi
    
    # Verify with checker only on first test to save time
    if [ -n "$CHECKER" ] && [ "$i" -eq 1 ]; then
        result=$(./push_swap $numbers | $CHECKER $numbers 2>&1)
        if [[ "$result" != "OK" ]]; then
            echo -e "    ${RED}⚠ CHECKER FAILED${NC}"
            fiveh_failed=$((fiveh_failed + 1))
        fi
    fi
done

fiveh_avg=$((fiveh_total / fiveh_count))
echo ""
echo -e "  ${BLUE}Statistics:${NC}"
echo -e "  ├─ Average:  ${YELLOW}$fiveh_avg${NC} ops"
echo -e "  ├─ Minimum:  ${YELLOW}$fiveh_min${NC} ops"
echo -e "  └─ Maximum:  ${YELLOW}$fiveh_max${NC} ops"
echo ""

if [ "$fiveh_avg" -lt 5500 ]; then
    echo -e "  Result: ${GREEN}✓ EXCELLENT - 100% Grade${NC}"
elif [ "$fiveh_avg" -lt 7000 ]; then
    echo -e "  Result: ${GREEN}✓ GOOD - Passing with margin${NC}"
elif [ "$fiveh_avg" -lt 8500 ]; then
    echo -e "  Result: ${YELLOW}✓ PASS - 80% Grade${NC}"
else
    echo -e "  Result: ${RED}✗ FAIL - Above 8500 average${NC}"
fi
echo ""

# ============================================================================
# FINAL SUMMARY
# ============================================================================

echo -e "${BLUE}╔════════════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║                    FINAL SUMMARY                           ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════════════════════════╝${NC}"
echo ""

# Calculate overall grade
grade=0

# 3 numbers (5 points)
if [ $three_max -le 3 ]; then
    grade=$((grade + 5))
    echo -e "  3 Numbers:   ${GREEN}✓ PASS${NC} (5/5 points)"
else
    echo -e "  3 Numbers:   ${RED}✗ FAIL${NC} (0/5 points)"
fi

# 5 numbers (10 points)
if [ $five_max -le 12 ]; then
    grade=$((grade + 10))
    echo -e "  5 Numbers:   ${GREEN}✓ PASS${NC} (10/10 points)"
else
    echo -e "  5 Numbers:   ${RED}✗ FAIL${NC} (0/10 points)"
fi

# 100 numbers (35 points for <700, 25 for <900, 15 for <1100)
if [ "$hundred_avg" -lt 700 ]; then
    grade=$((grade + 35))
    echo -e "  100 Numbers: ${GREEN}✓ EXCELLENT${NC} (35/35 points) - Avg: $hundred_avg ops"
elif [ "$hundred_avg" -lt 900 ]; then
    grade=$((grade + 25))
    echo -e "  100 Numbers: ${GREEN}✓ GOOD${NC} (25/35 points) - Avg: $hundred_avg ops"
elif [ "$hundred_avg" -lt 1100 ]; then
    grade=$((grade + 15))
    echo -e "  100 Numbers: ${YELLOW}✓ PASS${NC} (15/35 points) - Avg: $hundred_avg ops"
else
    echo -e "  100 Numbers: ${RED}✗ FAIL${NC} (0/35 points) - Avg: $hundred_avg ops"
fi

# 500 numbers (50 points for <5500, 35 for <7000, 20 for <8500)
if [ "$fiveh_avg" -lt 5500 ]; then
    grade=$((grade + 50))
    echo -e "  500 Numbers: ${GREEN}✓ EXCELLENT${NC} (50/50 points) - Avg: $fiveh_avg ops"
elif [ "$fiveh_avg" -lt 7000 ]; then
    grade=$((grade + 35))
    echo -e "  500 Numbers: ${GREEN}✓ GOOD${NC} (35/50 points) - Avg: $fiveh_avg ops"
elif [ "$fiveh_avg" -lt 8500 ]; then
    grade=$((grade + 20))
    echo -e "  500 Numbers: ${YELLOW}✓ PASS${NC} (20/50 points) - Avg: $fiveh_avg ops"
else
    echo -e "  500 Numbers: ${RED}✗ FAIL${NC} (0/50 points) - Avg: $fiveh_avg ops"
fi

echo ""
echo -e "${BLUE}═══════════════════════════════════════════════════════════${NC}"

if [ "$grade" -ge 100 ]; then
    echo -e "  ${GREEN}FINAL GRADE: $grade/100 - PERFECT! ⭐⭐⭐${NC}"
    echo -e "  ${GREEN}Eligible for bonus part!${NC}"
elif [ "$grade" -ge 90 ]; then
    echo -e "  ${GREEN}FINAL GRADE: $grade/100 - EXCELLENT! ⭐⭐${NC}"
elif [ "$grade" -ge 80 ]; then
    echo -e "  ${GREEN}FINAL GRADE: $grade/100 - GOOD! ⭐${NC}"
elif [ "$grade" -ge 60 ]; then
    echo -e "  ${YELLOW}FINAL GRADE: $grade/100 - PASSING${NC}"
else
    echo -e "  ${RED}FINAL GRADE: $grade/100 - NEEDS IMPROVEMENT${NC}"
fi

echo -e "${BLUE}═══════════════════════════════════════════════════════════${NC}"
echo ""

if [ -z "$CHECKER" ]; then
    echo -e "${YELLOW}⚠ Note: Checker not found. Results not verified for correctness.${NC}"
    echo -e "${YELLOW}  Download checker_OS from the intranet to verify sorting accuracy.${NC}"
    echo ""
fi