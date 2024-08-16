import pytest

# Helper function to import the correct module
def get_module(module_name):
    if module_name == 'cppfunctions':
        from cppfunctions import compute_days_interval, compute_months_interval, compute_days_interval_dt, compute_months_interval_dt
        from cppdatetime import datetime
    elif module_name == 'functions':
        from functions import compute_days_interval, compute_months_interval, compute_days_interval_dt, compute_months_interval_dt
        from datetime import datetime
    return compute_days_interval, compute_months_interval, compute_days_interval_dt, compute_months_interval_dt, datetime

@pytest.mark.parametrize("module_name", ["functions", "cppfunctions"])
def test_compute_days_interval(module_name):
    compute_days_interval, _, compute_days_interval_dt, _, datetime = get_module(module_name)
    assert compute_days_interval("2023-01-01", "2023-01-10") == 9
    assert compute_days_interval("2023-01-10", "2023-01-01") == 9
    assert compute_days_interval("2023-01-01", "2023-01-01") == 0
    assert compute_days_interval("2022-12-31", "2023-01-01") == 1
    assert compute_days_interval_dt(datetime(2023, 1, 1), datetime(2023, 1, 10)) == 9
    assert compute_days_interval_dt(datetime(2023, 1, 10), datetime(2023, 1, 1)) == 9

@pytest.mark.parametrize("module_name", ["functions", "cppfunctions"])
def test_compute_months_interval(module_name):
    _, compute_months_interval, _, compute_months_interval_dt, datetime = get_module(module_name)
    assert compute_months_interval("2023-01-01", "2023-02-01") == 1
    assert compute_months_interval("2023-01-01", "2023-04-01") == 3
    assert compute_months_interval("2023-01-01", "2023-01-01") == 0
    assert compute_months_interval("2022-01-01", "2023-01-01") == 12
    assert compute_months_interval_dt(datetime(2023, 1, 1), datetime(2023, 2, 1)) == 1
    assert compute_months_interval_dt(datetime(2023, 1, 1), datetime(2023, 4, 1)) == 3

if __name__ == '__main__':
    pytest.main()